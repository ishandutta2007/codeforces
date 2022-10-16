#include<bits/stdc++.h>
using namespace std;
int n;
void solve(vector<int>v){
	vector<int>nw;
	for(int i=0;i<v.size();i++)
		if(v[i]==v.size()){
			for(int j=i+1;j<v.size();j++)
				nw.push_back(v[j]);
			for(int j=0;j<i;j++)
				nw.push_back(v[j]);
			solve(nw);
			cout<<(i+1)%v.size()<<' ';
			break;
		}
}
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;vector<int>v;
		for(int i=0;i<n;i++){
			int x;
			cin>>x,v.push_back(x);
		}
		solve(v);cout<<endl;
	}
}