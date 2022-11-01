#include<iostream>
using namespace std;
#define R register int
string s[100000];
bool ct2[26][26],ct3[26][26][26];
inline void Solve(){
	int n;
	cin>>n;
	for(R i=0;i!=n;i++){
		cin>>s[i];
	}
	for(R i=0;i!=26;i++){
		for(R j=0;j!=26;j++){
			ct2[i][j]=false;
			for(R k=0;k!=26;k++){
				ct3[i][j][k]=false;
			}
		}
	}
	for(R i=0;i!=n;i++){
		int l=s[i].length();
		if(l==1){
			cout<<"YES"<<endl;
			return;
		}
		int a=s[i][0]-'a',b=s[i][1]-'a';
		if(l==2){
			if(a==b||ct2[b][a]==true){
				cout<<"Yes"<<endl;
				return;
			}
			for(R j=0;j!=26;j++){
				if(ct3[b][a][j]==true){
					cout<<"YES"<<endl;
					return;
				}
			}
			ct2[a][b]=true;
		}else{
			int c=s[i][2]-'a';
			if(a==c||ct3[c][b][a]==true||ct2[c][b]==true){
				cout<<"yes"<<endl;
				return;
			}
			ct3[a][b][c]=true;
		}
	}
	cout<<"NO"<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}