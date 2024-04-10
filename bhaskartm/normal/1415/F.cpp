#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int n;
const int N=5005;
int t[N];
int x[N];
int dp1[N];
bool dp2[N][N];

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	
	for(int i=1; i<=n; i++){
		cin>>t[i]>>x[i];
	}
	
	for(int i=0; i<N; i++){
		dp1[i]=1e18;
	}
	
	if(abs(x[1])>t[1]){
		cout<<"NO"<<endl;
		return 0;
	}
	
	
	dp1[1]=abs(x[1]);
	
	for(int i=2; i<=n; i++){
		if((abs(x[i])+abs(x[i]-x[1]))<=t[1]){
			dp2[1][i]=1;
		}
	}
	
	
	for(int i=1; i<n; i++){
		if((dp1[i]+abs(x[i+1]-x[i]))<=t[i+1]){
			dp1[i+1]=min(dp1[i+1], max(t[i], dp1[i]+abs(x[i+1]-x[i])));
		}
		for(int j=i+2; j<=n; j++){
			int t2=max(t[i], dp1[i]+abs(x[j]-x[i]));
			if((t2+abs(x[i+1]-x[j]))<=t[i+1]){
				dp2[i+1][j]=1;
			}
		}
		
		for(int j=i+1; j<=n; j++){
			if(dp2[i][j]){
				if(j==(i+1)){
					if((t[i]+abs(x[i+2]-x[i]))<=t[i+2]){
						dp1[i+2]=min(dp1[i+2], max(t[i+1], t[i]+abs(x[i+2]-x[i])));
					}
					for(int k=i+2; k<=n; k++){
						/*if((t[i]+abs(x[k]-x[i])+abs(x[i+1]-x[k]))<=t[i+1]){
							dp2[i+1][k]=1;
						}*/
						if(k!=(i+2)){
							int t1=t[i]+(abs(x[i]-x[k]));
							t1=max(t1, t[i+1]);
							if((t1+abs(x[k]-x[i+2]))<=t[i+2]){
								dp2[i+2][k]=1;
							}
							
						}
					}
				}
				else{
					if(t[i+1]>=(t[i]+abs(x[i+1]-x[i]))){
						dp2[i+1][j]=1;
					}
				}
			}
		}
	}
	
	if(dp2[n-1][n]==1 || dp1[n]<=t[n]){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	
	return 0;
}