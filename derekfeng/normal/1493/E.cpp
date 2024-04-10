#include<bits/stdc++.h>
using namespace std;
int n;
string L,R;
string plu(string s){
	for(int i=n-1;i>=0;i--){
		if(s[i]=='0'){s[i]='1';break;}
		else s[i]='0';
	}
	return s;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>n>>L>>R;
	if(L==R)cout<<L;
	else if(L[0]!=R[0]){for(int i=0;i<n;i++)putchar('1');}
	else if(R.back()=='1')cout<<R;
	else if(plu(L)==R)cout<<R;
	else cout<<plu(R);
}