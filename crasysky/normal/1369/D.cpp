#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
using namespace std;
const int N=2e6,P=1e9+7; int leaf[N+6],ans[N+6];
int main(){
	leaf[1]=1;
	rep(i,2,N){
		leaf[i]=(leaf[i-1]+2LL*leaf[i-2])%P;
		ans[i]=(ans[i-3]+leaf[i-2])%P;
	}
	int T; scanf("%d",&T);
	while (T--){
		int x; scanf("%d",&x); printf("%d\n",4LL*ans[x]%P);
	}
}