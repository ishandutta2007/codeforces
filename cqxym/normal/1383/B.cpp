#include<iostream>
using namespace std;
#define R register int
int ct[30],a[100000];
inline void Solve(){
	int n;
	scanf("%d",&n);
	for(R i=0;i!=30;i++){
		ct[i]=0;
	}
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
		for(R j=0;j!=30;j++){
			ct[j]+=a[i]>>j&1;
		}
	}
	for(R i=29;i!=-1;i--){
		if((ct[i]&1)==1){
			if((ct[i]&3)==3&&(n&1)==1){
				puts("LOSE");
				return;
			}
			puts("WIN");
			return;
		}
	}
	puts("DRAW");
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}