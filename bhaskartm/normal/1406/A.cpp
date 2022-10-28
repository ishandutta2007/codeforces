#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int cnt[105];
		for(int i=0; i<105; i++){
			cnt[i]=0;
		}
		for(int i=0; i<n; i++){
			int x;
			cin>>x;
			cnt[x]++;
		}
		int val1;
		int val2;
		for(int i=0; i<105; i++){
			if(cnt[i]>0){
				cnt[i]--;
			}
			else{
				val1=i;
				break;
			}
		}
		for(int i=0; i<105; i++){
			if(cnt[i]>0){
				cnt[i]--;
			}
			else{
				val2=i;
				break;
			}
		}
		cout<<val1+val2<<endl;
	}
	return 0;
}