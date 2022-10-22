#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,m;
bool vis[N];
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n>>m;
		for(i=1;i<=n;i++) vis[i]=0;
		for(i=1;i<=m;i++){
			int a,b,c;cin>>a>>b>>c;
			vis[b]=1;
		}
		for(i=1;i<=n;i++){
			if(!vis[i]){
				for(j=1;j<=n;j++)
					if(i!=j) cout<<j<<" "<<i<<endl;
				break;
			}
		}
	}
	return 0;
}