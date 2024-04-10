#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=1e6+6; const ll INF=1e18;
int c[3][N]; ll l[N];
int main(){
	static char s[N]; scanf("%s",s);
	int x,y,n=strlen(s); scanf("%d%d",&x,&y);
	if (x>y){
		swap(x,y);
		rep(i,0,n-1){
			if (s[i]=='0') s[i]='1';
			else if (s[i]=='1') s[i]='0';
		}
	}
	rep(i,1,n){
		c[0][i]=c[0][i-1],c[1][i]=c[1][i-1],c[2][i]=c[2][i-1];
		if (s[i-1]!='?') ++c[s[i-1]-'0'][i];
		else ++c[2][i];
	}
	ll s0=0;
	rep(i,1,n)
		if (s[i-1]=='1')
			s0+=(ll)c[0][i]*x+(ll)(c[0][n]-c[0][i])*y;
	rep(i,1,n){
		l[i]=l[i-1];
		if (s[i-1]=='?') l[i]+=(ll)c[1][i]*y+(ll)(c[1][n]-c[1][i-1])*x;
	}
	ll r=0,ans=l[n]+s0;
	per(i,n,1)
		if (s[i-1]=='?'){
			r+=(ll)c[0][i]*x+(ll)(c[0][n]-c[0][i])*y;
			ans=min(ans,l[i-1]+r+(ll)c[2][i-1]*(c[2][n]-c[2][i-1])*x+s0);
		}
	cout<<(ans==INF?s0:ans)<<endl;
	return 0;
}