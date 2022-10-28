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
	int n, q;
	cin>>n>>q;
	int num=0;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
		if(arr[i]==1){
			num++;
		}
	}
	while(q--){
		int ty;
		cin>>ty;
		if(ty==1){
			int x;
			cin>>x;
			if(arr[x]==1){
				num--;
				arr[x]=0;
			}
			else{
				arr[x]=1;
				num++;
			}
		}
		else{
			int k;
			cin>>k;
			if(k>num){
				cout<<0<<endl;
			}
			else{
				cout<<1<<endl;
			}
		}
	}
	
	return 0;
}