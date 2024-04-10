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
	int n;
	cin>>n;
	priority_queue<int>pq;
	int x;
	cin>>x;
	pq.push(x);
	int ans=0;
	for(int i=1; i<n; i++){
		int x;
		cin>>x;
		x-=i;
		if(x>=pq.top()){
			pq.push(x);
			continue;
		}
		else{
			ans+=(pq.top()-x);
			pq.push(x);
			pq.push(x);
			pq.pop();
		}
	}
	cout<<ans<<endl;
	
	return 0;
}