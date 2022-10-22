#include<bits/stdc++.h>
using namespace std;
#define int long long
const int inf=1e17;
const int N=200000;
int n;
char s[N+5];
int Uu[N+1],Dd[N+1],Ll[N+1],Rr[N+1],uU[N+2],dD[N+2],lL[N+2],rR[N+2],x[N+1],y[N+1];
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void mian(){
	cin>>s+1;
	n=strlen(s+1);
	int xn=0,yn=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='W')xn--;else if(s[i]=='S')xn++;else if(s[i]=='A')yn--;else yn++;
		x[i]=xn;y[i]=yn;
		Uu[i]=min(Uu[i-1],xn);Dd[i]=max(Dd[i-1],xn);Ll[i]=min(Ll[i-1],yn);Rr[i]=max(Rr[i-1],yn);
	}
	uU[n+1]=dD[n+1]=lL[n+1]=rR[n+1]=xn=yn=0;//
	for(int i=n;i;i--){
		int dxx=0,dyy=0;
		if(s[i]=='W')xn--,dxx--;else if(s[i]=='S')xn++,dxx++;else if(s[i]=='A')yn--,dyy--;else yn++,dyy++;
//		cout<<xn<<" "<<yn<<","<<dxx<<" "<<dyy<<"\n";
		uU[i]=min(0ll,min(uU[i+1]+dxx,xn));dD[i]=max(0ll,max(dD[i+1]+dxx,xn));lL[i]=min(0ll,min(lL[i+1]+dyy,yn));rR[i]=max(0ll,max(rR[i+1]+dyy,yn));
	}
//	for(int i=1;i<=n;i++)cout<<Uu[i]<<" "<<Dd[i]<<" "<<Ll[i]<<" "<<Rr[i]<<" "<<uU[i]<<" "<<dD[i]<<" "<<lL[i]<<" "<<rR[i]<<"\n";
	int ans=inf;
	for(int i=0;i<=n;i++)for(int j=0;j<4;j++){
		xn=x[i]+dx[j];yn=y[i]+dy[j];
		int u=min(Uu[i],min(xn,xn+uU[i+1])),d=max(Dd[i],max(xn,xn+dD[i+1])),l=min(Ll[i],min(yn,yn+lL[i+1])),r=max(Rr[i],max(yn,yn+rR[i+1]));
//		cout<<i<<" "<<j<<":"<<u<<" "<<d<<" "<<l<<" "<<r<<"\n";
		ans=min(ans,(d-u+1)*(r-l+1));
	}
	cout<<ans<<"\n";
}
signed main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}