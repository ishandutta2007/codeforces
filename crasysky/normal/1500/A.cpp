#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define ll long long
#define pb push_back
using namespace std;
const int N=1e6+6,S=1e7;
int a[N],p[S],q[S];
int main(){
	int n; scanf("%d",&n);
	rep(i,1,n) scanf("%d",&a[i]);
	rep(i,1,n)
		rep(j,i+1,n){
			int s=a[i]+a[j];
			if (p[s]&&p[s]!=i&&q[s]!=i&&q[s]!=j){
				printf("YES\n%d %d %d %d\n",p[s],q[s],i,j);
				return 0;
			}
			p[s]=i,q[s]=j;
		}
	puts("NO");
 	return 0;
}