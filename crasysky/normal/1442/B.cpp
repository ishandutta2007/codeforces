#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
using namespace std;
const int N=2e5+5,P=998244353;
int a[N],b[N],t[N],p[N],l[N],r[N];
void del(int x){ l[r[x]]=r[x],r[l[x]]=l[x]; }
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n,m,s=1; scanf("%d%d",&n,&m);
		rep(i,1,n) scanf("%d",&a[i]),p[a[i]]=i,t[i]=0;
		rep(i,1,m) scanf("%d",&b[i]),t[b[i]=p[b[i]]]=1;
		rep(i,1,n) l[i]=i-1,r[i]=i+1; t[0]=t[n+1]=1;
		rep(i,1,m){
			int x=b[i]; t[x]=0;
			if (t[l[x]]&&t[r[x]]) s=0;
			else if (!t[l[x]]&&!t[r[x]]) s=2LL*s%P;
			if (!t[l[x]]) del(l[x]);
			else if (!t[r[x]]) del(r[x]);
		}
		printf("%d\n",s);
	}
	return 0;
}