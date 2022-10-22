#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,m,x;
priority_queue<pii,vector<pii>,greater<pii> > q;
int ans[N];
int a[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n>>m>>x;
		for(i=1;i<=n;i++) cin>>a[i];
		while(!q.empty()) q.pop();
		for(i=1;i<=m;i++) q.push({0,i});
		cout<<"YES"<<endl;
		for(i=1;i<=n;i++){
			pii p=q.top();q.pop();
			cout<<p.second<<" ";
			p.first+=a[i];
			q.push(p);
		}
		cout<<endl;
	}
	return 0;
}