#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=1e9+7;
int cnt[500005];
vector<vector<int>>v;
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	mt19937_64 rnd(time(NULL));
	int n;
	cin>>n;
	int h[n+1];
	int h2[n+1];
	v.resize(n+1);
	for(int i=0; i<=n; i++){
		h[i]=rnd()%N;
		h2[i]=rnd()%N;
	}
	int arr[n];
	int la[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
		if(v[arr[i]].size()<3){
			la[i]=-1;
		}
		else{
			la[i]=v[arr[i]][v[arr[i]].size()-3]+1;
		}
		v[arr[i]].pb(i);
	}
	int ha[n+1];
	int ha2[n+1];
	ha[0]=0;
	ha2[0]=0;
	for(int i=0; i<n; i++){
		int val=cnt[arr[i]];
		if(val==2){
			ha[i+1]=((ha[i]-2*h[arr[i]])%N +N)%N;
			ha2[i+1]=((ha2[i]-2*h2[arr[i]])%N +N)%N;
		}
		else{
			ha[i+1]=(ha[i]+h[arr[i]])%N;
			ha2[i+1]=(ha2[i]+h2[arr[i]])%N;
		}
		cnt[arr[i]]=(cnt[arr[i]]+1)%3;
	}
	
	map<pair<int, int>, int>m;
	m[{ha[0], ha2[0]}]++;
	int pt=0;
	int ans=0;
	for(int i=1; i<=n; i++){
		int l=la[i-1];
		while(pt<l){
			m[{ha[pt], ha2[pt]}]--;
			pt++;
		}
		ans+=m[{ha[i], ha2[i]}];
		m[{ha[i], ha2[i]}]++;
	}
	
	cout<<ans;
	return 0;
}