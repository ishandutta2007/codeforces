#include<iostream>
using namespace std;
#define R register int
string s[5];
inline void Solve(){
	int n,m,x=9,y=9;
	cin>>n>>m;
	for(R i=0;i!=n;i++){
		cin>>s[i];
		for(R j=0;j!=m;j++){
			if(s[i][j]=='R'){
				if(x==9){
					x=i;
				}
				if(j<y){
					y=j;
				}
				break;
			}
		}
	}
	if(s[x][y]=='E'){
		cout<<"NO\n";
	}else{
		cout<<"YES\n";
	}
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}