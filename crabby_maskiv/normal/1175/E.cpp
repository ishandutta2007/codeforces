#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
const ll inf=0x3f3f3f3f;
const ll mod=998244353;
int n,m; 
vector<int> v[N];
int to[N][21];
int main(){
	ios::sync_with_stdio(0);
    int i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++){
    	int x,y;cin>>x>>y;
    	v[x].push_back(y);
	}
	int mx=0;
    for(i=0;i<N;i++){
    	for(auto k:v[i]) mx=max(mx,k);
    	if(mx<i) to[i][0]=i;
    	else to[i][0]=mx;
	}	
    for(j=1;j<=20;j++){
    	for(i=0;i<N;i++)
    		to[i][j]=to[to[i][j-1]][j-1];
	}
	while(m--){
		ll x,y;cin>>x>>y;
		int ans=0;
		for(i=20;i>=0;i--){
			if(to[x][i]<y){
				ans+=(1ll<<i);
				x=to[x][i];
			}
		}
		ans++;
		x=to[x][0];
		if(x<y){
			cout<<-1<<endl;
			continue;
		}
		cout<<ans<<endl;
	}
    return 0;
}