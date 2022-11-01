#include<iostream>
using namespace std;
#define R register int
inline int Calc(int a,int b){
	for(R i=19;i!=-1;i--){
		if((a>>i&1)==0&&(b>>i&1)==1){
			a|=1<<i;
			if(a>=b){
				return a;
			}
		}
	}
}
inline void Solve(){
	int a,b,x,ans;
	cin>>a>>b;
	ans=b-a;
	for(R i=a;i!=b;i++){
		x=Calc(i,b)+i-a-b+1;
		if(x<ans){
			ans=x;
		}
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}