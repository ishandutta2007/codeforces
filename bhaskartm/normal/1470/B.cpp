#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		map<int, int>ma;
		int maxi=0;
		for(int i=0; i<n; i++){
			cin>>arr[i];
			int val=arr[i];
			for(int x=2; x*x<=val; x++){
				while(val%(x*x)==0){
					val=val/(x*x);
				}
			}
			arr[i]=val;
			ma[val]++;
			maxi=max(maxi, ma[val]);
		}
		int q;
		cin>>q;
		map<int, int>ma2;
		int maxi2=0;
		for(auto it=ma.begin(); it!=ma.end(); it++){
			if((it->second)%2==0){
				ma2[1]+=(it->second);
			}
			else{
				ma2[(it->first)]+=(it->second);
			}
		}
		for(auto it=ma2.begin(); it!=ma2.end(); it++){
			maxi2=max(maxi2, it->second);
		}
		for(int i=0; i<q; i++){
			long long int x;
			cin>>x;
			if(x==0){
				cout<<maxi<<endl;
			}
			else{
				cout<<maxi2<<endl;
			}
		}
	}
	return 0;
}