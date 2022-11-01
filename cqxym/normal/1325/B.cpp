#include<stdio.h>
#include<set>
using namespace std;
#define R register int
set<int>Q;
inline void Solve(){
	Q.clear();
	int n,x;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		Q.insert(x);
	}
	printf("%d\n",Q.size());
}
int main(){
	int t,x;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}