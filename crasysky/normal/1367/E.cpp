#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=2e5+5; char s[N]; int c[50];
int gcd(int x,int y){ return y==0?x:gcd(y,x%y); }
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,k; scanf("%d%d%s",&n,&k,s);
		rep(i,1,26) c[i]=0;
		rep(i,0,n-1) ++c[s[i]-'a'+1];
		int ans=0;
		rep(i,1,n){
			int cnt=0,t=i/gcd(i,k);
			rep(j,1,26) cnt+=c[j]/t*t;
			if (cnt>=i) ans=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}