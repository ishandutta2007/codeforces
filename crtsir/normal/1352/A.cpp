#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,i=0,pw=1;
		cin>>n;
		vector<int>v; 
		while(n){
			if(n%10)
				v.push_back((n%10)*pw);
			n/=10;
			i++;pw*=10;
		}cout<<v.size()<<endl;
		for(int i=0;i<v.size();i++)
			cout<<v[i]<<' ';cout<<endl;
	} 
}