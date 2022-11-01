#include<iostream>
using namespace std;
#define R register int
int ct[26];
inline void Solve(){
	string s;
	cin>>s;
	for(R i=0;i!=26;i++){
		ct[i]=0;
	}
	int n=s.length();
	for(R i=0;i!=n;i++){
		ct[s[i]-'a']++;
	}
	int pos;
	for(R i=0;i!=n;i++){
		int x=s[i]-'a';
		if(ct[x]==1){
			pos=i;
			break;
		}
		ct[x]--;
	}
	for(R i=pos;i!=n;i++){
		cout<<s[i];
	}
	cout<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}