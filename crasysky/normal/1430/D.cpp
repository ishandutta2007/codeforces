#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=2e5+5; 
int a[N],sum[N]; char s[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,c=0,l=1; scanf("%d%s",&n,s);
		rep(i,1,n-1){
			if (s[i]!=s[i-1]) a[++c]=l,l=0;
			++l;
		}
		a[++c]=l,sum[c+1]=0;
		per(i,c,1) sum[i]=sum[i+1]+a[i];
		int ans=0;
		for (int i=1,h=0;i<=c;++i){
			int t=max(h-(a[i]-2),0);
			if (t<=sum[i+1]+1) ++ans,h=t;
			else h=max(h-a[i],0);
		}
		printf("%d\n",ans);
	}
	return 0;
}