#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

int t, n, a[105], k;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>k;

		for(int i = 0; i < n; i++){
			cin>>a[i];
		}

		int sum = 0;
		for(int i = 0; i < n; i++){
			int ok = 1;
			while(ok){
				ok = 0;
				for(int j = i-1; j >= 0; j--){
					if(a[j] < a[j+1]){
						a[j]++;
						sum++;
						ok = 1;
						if(sum == k){
							cout<<j+1<<'\n';
							goto out;
						}
					}
				}
			}
		}
		cout<<"-1\n";
		out:;
	}
}