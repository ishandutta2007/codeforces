#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,m;
bool vis[N];
int p[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++){
			if(vis[i]) continue;
			vector<int> v;
			while(1){
				cout<<"? "<<i<<endl;
				int x;cin>>x;
				if(v.size()&&v[0]==x) break;
				v.push_back(x);
			}
			m=v.size();
			for(j=0;j<m;j++){
				p[v[j]]=v[(j+1)%m];
				vis[v[j]]=1;
			}
		}
		cout<<"! ";
		for(i=1;i<=n;i++) cout<<p[i]<<" ";
		cout<<endl;
		for(i=1;i<=n;i++) vis[i]=0;
	}
	return 0;
}