#include<stdio.h>
#include<vector>
using namespace std;
#define L long long
vector<L>A;
int main(){
	L u,v;
	scanf("%lld%lld",&u,&v);
	while(v!=0){
		L tem=v-u;
		if(tem<0||(tem&1)==1){
			printf("-1");
			return 0;
		}
		tem>>=1;
		if(tem==0){
			tem=v;
		}
		A.push_back(tem);
		u^=tem;
		v-=tem;
	}
	printf("%d\n",A.size());
	for(vector<L>::iterator T=A.begin();T!=A.end();T++){
		printf("%lld ",*T);
	}
	return 0;
}