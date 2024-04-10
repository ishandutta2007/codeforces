#include<bits/stdc++.h>
using namespace std;
int main(){
	string S,T,U;
	cin>>S>>T;
	for(int i=0;i<S.size();i++){
		if(S[i]<T[i]){cout<<"-1"<<endl;return 0;}
		U+=T[i];
	}
	cout<<U<<endl;
	return 0;
}