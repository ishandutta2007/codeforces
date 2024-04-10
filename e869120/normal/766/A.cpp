#include<bits/stdc++.h>
using namespace std;
int main(){
	string S,T;cin>>S>>T;
	if(S==T)cout<<"-1"<<endl;
	else cout<<max(S.size(),T.size())<<endl;
	return 0;
}