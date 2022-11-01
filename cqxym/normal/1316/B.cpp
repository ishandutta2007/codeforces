#include<iostream>
using namespace std;
#define R register int
inline void Solve(){
	int n;
	cin>>n;
	string s,ans;
	int id=1;
	cin>>s;
	ans=s;
	for(R i=2;i<=n;i++){
		string t="";
		for(R j=i-1;j!=n;j++){
			t+=s[j];
		}
		string u="";
		for(R j=0;j!=i-1;j++){
			u+=s[j];
		}
		if(((n^i)&1)==0){
			string v="";
			for(R j=i-2;j!=-1;j--){
				v+=u[j];
			}
			u=v;
		}
		t+=u;
		if(t<ans){
			ans=t;
			id=i;
		}
	}
	cout<<ans<<endl;
	cout<<id<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}