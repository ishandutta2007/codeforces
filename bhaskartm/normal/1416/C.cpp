#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=3e5+5;
int n;
int arr[N];
int cnt1[31];
int cnt2[31];

void f(vector<int>v, int ind){
	if(ind==-1 || v.empty()){
		return;
	}
	vector<int>vec;
	vector<int>v1;
	vector<int>v2;
	for(auto u:v){
		if((u&(1<<ind))){
			vec.pb(1);
			v1.pb(u);
		}
		else{
			vec.pb(0);
			v2.pb(u);
		}
	}
	int tot=0;
	int one=0;
	int zero=0;
	for(auto u:vec){
		if(u==0){
			tot+=one;
			zero++;
		}
		else{
			one++;
		}
	}
	cnt1[ind]+=tot;
	cnt2[ind]+=(one*zero-tot);
	f(v1, ind-1);
	f(v2, ind-1);
}

 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	vector<int>v;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		v.pb(arr[i]);
	}
	f(v, 30);
	int mini=0;
	int ans=0;
	for(int i=0; i<=30; i++){
		mini+=min(cnt1[i], cnt2[i]);
		if(cnt2[i]<cnt1[i]){
			ans+=(1<<i);
		}
	}
	cout<<mini<<" "<<ans<<endl;
	return 0;
}