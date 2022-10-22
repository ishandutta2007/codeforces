#include<cstdio>
#include<algorithm>
typedef long long ll;
const int N=1e5+3,A=1e9;
int n,a[N],b,c,d;ll s;
inline ll Calc(int g,int b,int c){
	ll res=0;
	for(int i=1;i<=n;i++)
	  if(a[i]<g)res+=(ll)(g-a[i])*b;
	  else res+=(ll)(a[i]-g)*c;
	return res;
}
inline ll Solve(int l,int r,int b,int c){
	ll res=std::min(Calc(l,b,c),Calc(r,b,c)),r0,r1;
	int md0,md1;
	for(;l<r;){
	  md0=l+r>>1,md1=md0+1;
	  r0=Calc(md0,b,c),r1=Calc(md1,b,c);
	  if(r0>=r1)l=md1;
	  else r=md0;
	}
	return std::min(res,std::min(Calc(l,b,c),Calc(r,b,c)));
}
int main(){
	scanf("%d%d%d%d",&n,&b,&c,&d);
	for(int i=1;i<=n;i++)scanf("%d",a+i),s+=a[i];
	if(b+c<=d)printf("%lld\n",Solve(0,A,b,c));
	else printf("%lld\n",std::min(Solve(0,s/n,d-c,c),Solve(s/n+1,A,b,d-b)));
	return 0;
}