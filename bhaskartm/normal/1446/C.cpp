#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=2e5+5;
int arr[N];
int n;

int f(vector<int>v, int ind){
	if(v.empty()){
		return 0;
	}
	if(ind==-1){
		return int(v.size());
	}
	vector<int>v1;
	vector<int>v2;
	for(auto u:v){
		if((u&(1<<ind))){
			v1.pb(u);
		}
		else{
			v2.pb(u);
		}
	}
	if(v1.empty()){
		return f(v2, ind-1);
	}
	if(v2.empty()){
		return f(v1, ind-1);
	}
	return 1+max(f(v1, ind-1), f(v2, ind-1));
}

 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	vector<int>v;
	
	for(int i=0; i<n; i++){
		cin>>arr[i];
		v.pb(arr[i]);
	}
	cout<<n-f(v, 30)<<endl;
	return 0;
}