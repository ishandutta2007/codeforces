#include<iostream>
using namespace std;
#define R register int
string s[500];
inline void Solve(){
	int n,m;
	cin>>n>>m;
	for(R i=0;i!=n;i++){
		cin>>s[i];
		if(i%3==1){
			for(R j=0;j!=m;j++){
				s[i][j]='X';
			}
		}
	}
	if(n==1){
		for(R j=0;j!=m;j++){
			cout<<'X';
		}
		cout<<endl;
		return;
	}
	for(R i=4;i<n;i+=3){
		int x=-1,y;
		for(R j=0;j!=m;j++){
			if(s[i-2][j]=='X'){
				x=i-2;
				y=j;
				break;
			}
			if(s[i-1][j]=='X'){
				x=i-1;
				y=j;
				break;
			}
		}
		if(x==-1){
			s[i-2][0]=s[i-1][0]='X';
		}else{
			s[i-2][y]=s[i-1][y]='X';
		}
	}
	if(n%3==1){
		for(R i=0;i!=m;i++){
			if(s[n-1][i]=='X'){
				s[n-2][i]='X';
			}
		}
	}
	for(R i=0;i!=n;i++){
		cout<<s[i]<<endl;
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