#include<iostream>
using namespace std;
#define L long long
#define R register int
L a1[26],a2[26][26];
inline void Max(L &x,L &y){
	x=x>y?x:y;
}
int main(){
	string S;
	cin>>S;
	int l=S.length();
	for(R i=0;i!=l;i++){
	    int c=S[i]-'a';
	    for(R j=0;j!=26;j++){
	    	a2[j][c]+=a1[j];
		}
	    a1[c]++;
	}
	L ans=0;
	for(R i=0;i!=26;i++){
		Max(ans,a1[i]);
	}
	for(R i=0;i!=26;i++){
		for(R j=0;j!=26;j++){
			Max(ans,a2[i][j]);
		}
	}
	cout<<ans;
	return 0;
}