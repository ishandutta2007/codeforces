#include<bits/stdc++.h>
using namespace std;
int main(){
	string S;int n,a,b;cin>>n>>a>>b>>S;a--;b--;
	if(S[a]==S[b])cout<<"0"<<endl;
	else cout<<"1"<<endl;
	return 0;
}