#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>vec;
int n;string S;
int solve(vector<pair<int,int>>x){
	for(int i=0;i<x.size();i++){
		if(x[i].second>=3)return 2;
	}
	int cnt1=0;
	for(int i=0;i<x.size();i++){
		if(x[i].second>=2)cnt1++;
	}
	if(cnt1>=2)return 2;
	if(cnt1>=1)return 1;
	return 0;
}
int main(){
	cin>>n>>S;int cnt=1;
	for(int i=1;i<S.size();i++){
		if(S[i-1]!=S[i]){vec.push_back(make_pair(S[i-1]-'0',cnt));cnt=1;}
		else{cnt++;}
	}
	vec.push_back(make_pair(S[S.size()-1]-'0',cnt));
	int E=vec.size();
	E+=solve(vec);
	cout<<E<<endl;
	return 0;
}