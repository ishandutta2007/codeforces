#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int MOD=1e9+7;
const int N=(1<<20);
int cnt[N];
int po[N];
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	po[0]=1;
	for(int i=1; i<N; i++){
		po[i]=(2*po[i-1])%MOD;
	}
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		cnt[x]++;
	}
	
	for(int i=0; i<20; i++){
		for(int mask=0; mask<N; mask++){
			if(!(mask&(1<<i))){
				cnt[mask]+=cnt[mask^(1<<i)];
			}
		}
	}
	int ans=0;
	
	for(int i=0; i<N; i++){
		int num=__builtin_popcount(i);
		if(num%2==0){
			ans=(ans+po[cnt[i]]+MOD-1)%MOD;
		}
		else{
			ans=(ans-po[cnt[i]]+MOD+1)%MOD;
		}
	}
	cout<<ans;
	return 0;
}