#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=1e5+5;
int arr[N];

 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int q;
	cin>>q;
	while(q--){
		int u, v;
		cin>>u>>v;
		if(u>v){
			cout<<"NO"<<endl;
			continue;
		}
		bool che=1;
		for(int i=30; i>=0; i--){
			if(u>=(1<<i)){
				u-=(1<<i);
			}
			if(v>=(1<<i)){
				v-=(1<<i);
			}
			if(__builtin_popcount(u)<__builtin_popcount(v)){
				che=0;
			}
		}
		if(che){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}