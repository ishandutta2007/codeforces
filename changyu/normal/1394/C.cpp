#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
const int N=5e5+3,A=5e5+1,B=1e6+1;
int n,a[N],b[N],mnx,mxx,mny,mxy,mnz,mxz,ansx,ansy;
std::string s[N],ans;
inline bool Check(int g){
	mnx=mny=mnz=B;
	mxx=mxy=0,mxz=-B;
	for(int i=1;i<=n;i++){
	  mnx=std::min(mnx,a[i]+g);
	  mxx=std::max(mxx,a[i]-g);
	  mny=std::min(mny,b[i]+g);
	  mxy=std::max(mxy,b[i]-g);
	  mnz=std::min(mnz,b[i]-a[i]+g);
	  mxz=std::max(mxz,b[i]-a[i]-g);
	}
	return mnx>=mxx&&mny>=mxy&&mnz>=mxz&&mny-mxx>=mxz&&mxy-mnx<=mnz;
}
inline void Checkpoint(int x,int y,int g){
	int res=0;
	for(int i=1;i<=n;i++){
	  if(a[i]>=x&&b[i]>=y)res=std::max(res,std::max(a[i]-x,b[i]-y));
	  if(a[i]< x&&b[i]>=y)res=std::max(res,x-a[i]+b[i]-y);
	  if(a[i]>=x&&b[i]< y)res=std::max(res,a[i]-x+y-b[i]);
	  if(a[i]< x&&b[i]< y)res=std::max(res,std::max(x-a[i],y-b[i]));
	}
	if(res<=g)ansx=x,ansy=y;
}
signed main(){
	int l,r,m;
	std::cin>>n;
	for(int i=1;i<=n;++i){
	  std::cin>>s[i];
	  for(int j=0;j<s[i].size();j++)s[i][j]=='N'?++a[i]:++b[i];
	}
	for(l=0,r=A;l<r;)m=l+r>>1,Check(m)?r=m:l=m+1;
	printf("%d\n",l);
	Check(l);
	Checkpoint(mxx,mxy,l);
	Checkpoint(mxx,mny,l);
	Checkpoint(mnx,mxy,l);
	Checkpoint(mnx,mny,l);
	Checkpoint(mxx,mxx+mxz,l);
	Checkpoint(mnx,mnx+mxz,l);
	Checkpoint(mxy-mxz,mxy,l);
	Checkpoint(mny-mxz,mny,l);
	Checkpoint(mxx,mxx+mnz,l);
	Checkpoint(mnx,mnx+mnz,l);
	Checkpoint(mxy-mnz,mxy,l);
	Checkpoint(mny-mnz,mny,l);
	for(;ansx--;)ans+="N";
	for(;ansy--;)ans+="B";
	std::cout<<ans; 
	return 0;
}