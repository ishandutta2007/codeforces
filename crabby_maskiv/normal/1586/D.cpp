#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=100+5;
int n,m;
vector<int> g[N];
int deg[N];
int answ[N];
int main(){
	int i,j;
	cin>>n;
	for(i=2;i<=n;i++){
		cout<<"? ";
		for(j=1;j<i;j++) cout<<2<<" ";
		cout<<1<<" ";
		for(j=i+1;j<=n;j++) cout<<2<<" ";
		cout<<endl;
		fflush(stdout);
		int ans;cin>>ans;
		if(ans>0&&ans<i){
			deg[i]++;
			g[ans].pb(i);
		}
	}
	for(i=2;i<=n;i++){
		cout<<"? ";
		for(j=1;j<i;j++) cout<<1<<" ";
		cout<<2<<" ";
		for(j=i+1;j<=n;j++) cout<<1<<" ";
		cout<<endl;
		fflush(stdout);
		int ans;cin>>ans;
		if(ans>0&&ans<i){
			g[i].pb(ans);
			deg[ans]++;
		}
	}
	queue<int> q;
	for(i=1;i<=n;i++){
		if(!deg[i]) q.push(i);
	}
	int tot=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		answ[u]=++tot;
		for(auto v:g[u]){
			deg[v]--;
			if(!deg[v]) q.push(v);
		}
	}
	cout<<"! ";
	for(i=1;i<=n;i++) cout<<answ[i]<<" ";
	fflush(stdout);
	return 0;
}