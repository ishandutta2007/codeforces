#include<iostream>
using namespace std;
#define R register int
inline void GetString(string&s,int n,int k,string&t){
	int lt=0;
	for(R i=k;i!=0;i--){
		t+=s[lt];
		lt++;
		if(lt==n){
			lt=0;
		}
	}
}
int main(){
	int n,k;
	cin>>n>>k;
	string s,t;
	cin>>s;
	for(R i=k;i!=0;i--){
		t+=s[0];
	}
	for(R i=n;i!=1;i--){
		string b;
		GetString(s,i,k,b);
		if(b<t){
			t=b;
		}
		s.pop_back();
	}
	cout<<t;
	return 0;
}