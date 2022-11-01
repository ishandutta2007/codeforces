#include<iostream>
using namespace std;
#define R register int
inline void Solve(){
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(R i=0;i!=m&&i<=n;i++){
		string t=s;
		for(R j=0;j!=n;j++){
			int ct=0;
			if(j!=0&&s[j-1]=='1'){
				ct=1;
			}
			if(j!=n-1&&s[j+1]=='1'){
				ct^=1;
			}
			if(ct==1){
				t[j]='1';
			}
		}
		s=t;
	}
	cout<<s<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=t;i!=0;i--){
		Solve();
	}
	return 0;
}