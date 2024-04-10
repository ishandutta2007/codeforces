#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define vit vector<int>::iterator
#define sit set<pr>::iterator
#define pb push_back
#define ll long long
using namespace std;
const int N=1e5+5; int a[N];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		int n; scanf("%d",&n);
		rep(i,1,n) scanf("%d",&a[i]);
		printf("%d\n",3*n);
		rep(i,1,n/2){
			int p=2*i-1,q=2*i;
			printf("2 %d %d\n",p,q);
			printf("2 %d %d\n",p,q);
			printf("1 %d %d\n",p,q);
			printf("2 %d %d\n",p,q);
			printf("2 %d %d\n",p,q);
			printf("1 %d %d\n",p,q);
		}
	}
	return 0;
}