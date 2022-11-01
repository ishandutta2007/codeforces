#include<stdio.h>
#include<map>
#include<set>
using namespace std;
#define R register int
map<int,long long>A;
set<int>B;
inline void Max(long long &x,long long y){
	x=x>y?x:y;
}
int main(){
	int n,x;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		B.insert(x-i);
		A[x-i]+=x;
	}
	long long ans=0;
	for(set<int>::iterator T=B.begin();T!=B.end();T++){
		Max(ans,A[*T]);
	}
	printf("%lld",ans);
	return 0;
}