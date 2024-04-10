#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;
vector<pair<int,int> > v;
int main(){
	int i,j;
	cin>>n;
	int cnt=0;
	if(n==1){
		v.push_back({0,0});
		cnt=1;
	}
	while(n>=2){
		v.push_back({cnt,0});
		v.push_back({cnt+1,-1});
		v.push_back({cnt+1,0});
		v.push_back({cnt+1,1});
		v.push_back({cnt+2,-1});
		v.push_back({cnt+2,0});
		v.push_back({cnt+2,1});
		v.push_back({cnt+3,0});
		cnt+=4;
		n-=2;
	}
	v.push_back({-1,0});
	v.push_back({-1,1});
	v.push_back({-1,2});
	v.push_back({-1,3});
	for(i=0;i<=cnt;i++) v.push_back({i,3});
	v.push_back({cnt,0});
	v.push_back({cnt,1});
	v.push_back({cnt,2});
	if(n==1){
		v.push_back({-1,-1});
		v.push_back({-2,-1});
		v.push_back({-2,0});
	}
	cout<<v.size()<<endl;
	for(auto x:v) cout<<x.first<<" "<<x.second<<endl;
	return 0;
}