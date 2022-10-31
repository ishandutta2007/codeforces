#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e6+6; 
char s1[N],s2[N]; int a1[N],a2[N],p[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
	    int n; scanf("%d%s%s",&n,s1,s2);
	    rep(i,1,n) a1[i]=s1[i-1]-'0',a2[i]=s2[i-1]-'0';
	    int m=0;
	    per(i,n,1){
	    	int x=a1[(n-i&1?i+1:1)+(n-i>>1)]; if (n-i&1) x^=1;
	    	if (x==a2[i]) p[++m]=1; p[++m]=i;
	    }
	    printf("%d ",m); rep(i,1,m) printf("%d ",p[i]);
	    putchar('\n');
	}
	return 0;
}