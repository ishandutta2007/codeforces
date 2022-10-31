#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=110,INF=1e9;
char s[N],t[N][N]; int dp[N],la[N],w[N];
int main(){
	int T; cin>>T;
	while (T--){
		scanf("%s",s);
		int n; scanf("%d",&n);
		rep(i,1,n) scanf("%s",t[i]);
		int l=strlen(s);
		rep(i,1,l){
			dp[i]=INF;
			rep(j,1,n){
				int l2=strlen(t[j]);
				if (i<l2) continue;
				bool f=false;
				rep(k,1,l2) if (s[i-l2+k-1]!=t[j][k-1]){ f=true; break; }
				if (f) continue;
				rep(k,1,l2) 
                    if (dp[i-k]+1<dp[i]) dp[i]=dp[i-k]+1,la[i]=i-k,w[i]=j;
			}
		}
		if (dp[l]>=INF) puts("-1");
		else{
            printf("%d\n",dp[l]);
            for (int i=l;i;i=la[i]) printf("%d %d\n",w[i],i-strlen(t[w[i]])+1);
        }
	}
	return 0;
}