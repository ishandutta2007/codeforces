#include<iostream>
#include<map>
using namespace std;
int n,m;string S[1100],T[1100];
map<string,int>M;
int main(){
	cin>>n>>m;int D=0;
	for(int i=0;i<n;i++){cin>>S[i];M[S[i]]++;}
	for(int i=0;i<m;i++){cin>>T[i];M[T[i]]++;}
	if(n<m){cout<<"NO"<<endl;}
	if(n>m){cout<<"YES"<<endl;}
	if(n==m){
		for(int i=0;i<n;i++){D+=M[S[i]]-1;}
		if(D%2==1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}