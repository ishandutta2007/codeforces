#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
const int N=505;
const int M=1e9;

int dp[N];//odd
int pa[N];
int n, k;
int val[N];



 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>k;
	queue<int>qu;
	for(int i=0; i<=n; i++){
		dp[i]=M;
	}
	dp[n]=0;
	pa[n]=-1;
	qu.push(n);
	
	while(!qu.empty()){
		int u=qu.front();
		qu.pop();
		int odd=u;
		int even=n-u;
		for(int i=0; i<=odd; i++){
			if(even>=k-i && k-i>=0){
				if(dp[odd+k-2*i]>1+dp[odd]){
					dp[odd+k-2*i]=1+dp[odd];
					pa[odd+k-2*i]=k-i;
					qu.push(odd+k-2*i);
				}
			}
		}
	}
	if(dp[0]==M){
		cout<<-1<<endl;
		return 0;
	}
	int node=0;
	int ans=0;
	while(1){
		if(node==n){
			cout<<"! "<<ans<<endl;
			return 0;
		}
		int od=pa[node];
		int ev=k-od;
		cout<<"? ";
		for(int i=1; i<=n; i++){
			if(ev>0 && val[i]%2==0){
				cout<<i<<" ";
				ev--;
				val[i]++;
			}
			else if(od>0 && val[i]%2==1){
				cout<<i<<" ";
				od--;
				val[i]++;
			}
		}
		cout<<endl;
		int x;
		cin>>x;
		ans=ans^x;
		node=node+k-2*pa[node];
	}
	
	return 0;
}