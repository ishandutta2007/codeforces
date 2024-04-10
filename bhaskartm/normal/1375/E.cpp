#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)
int arr[10000];
int n;
int main() {
	cin>>n;
	rep(i,0,n)cin>>arr[i];
	vector<pair<int,pair<int,int>> >V;
	rep(i,0,n){
		rep(j,i+1,n){
			if(arr[i]>arr[j])V.push_back({arr[i],{i,-j}});
		}
	}
	sort(V.begin(),V.end());
	cout<<V.size()<<endl;
	rep(i,0,V.size()){
		cout<<V[i].second.first+1<<" "<<-V[i].second.second+1<<endl;
	}
	return 0;
}