#include<iostream>
using namespace std;
#define R register int
int ct1[101][26],ct2[101][26];
string s,t;
inline void Solve(){
	cin>>s>>t;
	int l1=s.length(),l2=t.length();
	if(l1>l2){
		puts("NO");
		return;
	}
	for(R i=0;i<101;i++){
		for(R j=0;j<26;j++){
			ct1[i][j]=ct2[i][j]=0;
		}
	}
	for(R i=0;i<l1;i++){
		for(R j=0;j<26;j++){
			ct1[i+1][j]=ct1[i][j];
		}
		ct1[i+1][s[i]-'a']++;
	}
	for(R i=0;i<l2;i++){
		for(R j=0;j<26;j++){
			ct2[i+1][j]=ct2[i][j];
		}
		ct2[i+1][t[i]-'a']++;
	}
	for(R i=l1;i<=l2;i++){
		bool tag=true;
		for(R j=0;j<26;j++){
			if(ct2[i][j]-ct2[i-l1][j]!=ct1[l1][j]){
				tag=false;
				break;
			}
		}
		if(tag==true){
			puts("YES");
			return;
		}
	}
	puts("NO");
}
int main(){
	int n;
	cin>>n;
	for(R i=0;i<n;i++){
		Solve();
	}
	return 0;
}