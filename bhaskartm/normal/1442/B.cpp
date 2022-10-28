#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=998244353;
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		int arr[n];
		int l[n];
		int r[n];
		int position[n+1];
		for(int i=0; i<n; i++){
			cin>>arr[i];
			position[arr[i]]=i;
		}
		for(int i=1; i<n; i++){
			l[arr[i]]=arr[i-1];
		}
		for(int i=0; i<n-1; i++){
			r[arr[i]]=arr[i+1];
		}
		l[arr[0]]=-1;
		r[arr[n-1]]=-1;
		
		int b[k];
		int nums[k];
		int pos[n+1];
		for(int i=1; i<=n; i++){
			pos[i]=1;
		}
		for(int i=0; i<k; i++){
			cin>>b[i];
			nums[i]=b[i];
			pos[b[i]]=0;
		}
		int ans=1;
		for(int i=0; i<k; i++){
			int num=b[i];
			if(l[num]!=-1 && r[num]!=-1 && pos[l[num]]==1 && pos[r[num]]==1){
				ans=(ans*2)%N;
				pos[l[num]]=0;
				l[num]=l[l[num]];
				if(l[num]!=-1){
					r[l[num]]=num;
				}
				pos[b[i]]=1;
				continue;
			}
			if(!((l[num]!=-1 && pos[l[num]]==1) || (r[num]!=-1 && pos[r[num]]==1))){
				ans=0;
				break;
			}
			if(l[num]!=-1 && pos[l[num]]==1){
				pos[l[num]]=0;
				l[num]=l[l[num]];
				if(l[num]!=-1){
					r[l[num]]=num;
				}
				pos[b[i]]=1;
				continue;
			}
			if(r[num]!=-1 && pos[r[num]]==1){
				pos[r[num]]=0;
				r[num]=r[r[num]];
				if(r[num]!=-1){
					l[r[num]]=num;
				}
				pos[b[i]]=1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}