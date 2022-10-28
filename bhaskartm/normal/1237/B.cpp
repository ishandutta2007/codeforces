#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define int long long int 
int n;
vector<int>bit;

int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    
void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }

main() {
	cin>>n;
	bit.resize(n);
	int arr[n];
	int val[n+1];
	for(int i=n-1; i>=0; i--){
		cin>>arr[i];
		val[arr[i]]=i;
	}
	int b[n];
	for(int i=n-1; i>=0; i--){
		cin>>b[i];
		b[i]=val[b[i]];
	}
	

	int ans=0;
	for(int i=n-1; i>=0; i--){
		add(b[i], 1);
		int num=sum(n-1)-sum(b[i]);
		if(num!=n-b[i]-1){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}