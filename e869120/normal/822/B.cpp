#include<bits/stdc++.h>
using namespace std;
int n,m,minx=1e9;string S,T;vector<int>D;
int main(){
	cin>>n>>m>>S>>T;
	for(int i=0;i<=T.size()-S.size();i++){
		int cnt=0;vector<int>E;
		for(int j=0;j<S.size();j++){if(S[j]!=T[i+j]){cnt++;E.push_back(j+1);}}
		if(minx>cnt){minx=cnt;D=E;}
	}
	cout<<minx<<endl;
	for(int i=0;i<D.size();i++){if(i)cout<<' ';cout<<D[i];}cout<<endl;
	return 0;
}