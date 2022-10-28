#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

int fu(vector<int>v, int x){
	for(int i=0; i<v.size(); i++){
		if(v[i]==x){
			return i;
		}
	}
}

vector<int>rev(vector<int>vec, int ind){
	vector<int>ret;
	for(int i=0; i<=ind; i++){
		ret.pb(vec[i]);
	}
	reverse(ret.begin(), ret.end());
	for(int i=ind+1; i<vec.size(); i++){
		ret.pb(vec[i]);
	}
	return ret;
}
 
 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>v;
		bool b=1;
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			v.pb(x);
			if((v[i]%2)==(i%2)){
				b=0;
			}
		}
		if(b==0){
			cout<<-1<<endl;
			continue;
		}
		vector<int>ans;
		for(int i=n; i>1; i-=2){
			int pos=fu(v, i);
			v=rev(v, pos);
			ans.pb(pos);
			pos=fu(v, i-1);
			v=rev(v, pos-1);
			ans.pb(pos-1);
			pos=i-1;
			v=rev(v, pos);
			ans.pb(pos);
			pos=fu(v, i);
			v=rev(v, pos);
			ans.pb(pos);
			pos=i-1;
			v=rev(v, pos);
			ans.pb(pos);
		}
		int sz=ans.size();
		cout<<sz<<endl;
		for(auto u:ans){
			cout<<u+1<<" ";
		}
		cout<<endl;
	}
	return 0;
}