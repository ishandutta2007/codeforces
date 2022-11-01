#include<iostream>
using namespace std;
#define R register int
int c[1000][5];
inline bool Check(int n,int x,int y){
	int ct1=0,ct2=0;
	for(R i=0;i!=n;i++){
		if(c[i][x]==0&&c[i][y]==0){
			return false;
		}
		if(c[i][x]==0){
			ct2+=2;
		}
		if(c[i][y]==0){
			ct1+=2;
		}
	}
	if(ct1<=n&&ct2<=n){
		return true;
	}
	return false;
}
inline void Solve(){
	int n;
	cin>>n;
	for(R i=0;i!=n;i++){
		for(R j=0;j!=5;j++){
			cin>>c[i][j];
		}
	}
	if((n&1)==1){
		cout<<"NO"<<endl;
		return;
	}
	for(R i=1;i!=5;i++){
		for(R j=0;j!=i;j++){
			if(Check(n,i,j)==true){
				cout<<"Yes"<<endl;
				return;
			}
		}
	}
	cout<<"No"<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}