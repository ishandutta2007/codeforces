#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i) 
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define db long double
using namespace std;
const int N=1e6+6; int a[N];
int main(){
	int n,q,c=0; scanf("%d%d",&n,&q);
	rep(i,1,n) scanf("%d",&a[i]),c+=a[i];
	while (q--){
		int op; scanf("%d",&op);
		if (op==1){
			int x; scanf("%d",&x);
			if (a[x]==0) ++c; else --c;
			a[x]^=1;
		}
		else{
			int k; scanf("%d",&k);
			printf("%d\n",k<=c?1:0);
		}
	}
	return 0;
}