#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6; char s[N]; int l[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d%s",&n,s);
		int m=1; l[1]=1;
		rep(i,1,n-1)
			if (s[i]==s[i-1]) ++l[m];
			else l[++m]=1;
		if (m>1&&s[n-1]==s[0]) l[1]+=l[m--];
		if (m>1){
			int ans=0; rep(i,1,m) ans+=l[i]/3;
			printf("%d\n",ans);
		}
		else printf("%d\n",(n+2)/3);
	}
	return 0;
}