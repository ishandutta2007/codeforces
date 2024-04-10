#include<stdio.h>
#include<set>
using namespace std;
#define R register int
set<int>Q;
inline void Solve(){
	int n,s=0,x;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		Q.insert(x);
	}
	set<int>::iterator t;
	while(Q.end()!=Q.begin()){
		t=Q.end();
		t--;
		x=*t;
		if((x&1)==0){
			s++;
			Q.insert(x>>1);
		}
		Q.erase(x);
	}
	printf("%d\n",s);
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}