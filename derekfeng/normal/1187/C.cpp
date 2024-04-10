#include <bits/stdc++.h>
using namespace std;
int n,m;
bool vis[1003];
vector <pair<int,int> > v;
int main(){ 
	cin>>n>>m;
	for (int i=0;i<m;i++){
		int t,l,r;cin>>t>>l>>r;
		if (t==1) for (int j=l+1;j<=r;j++) vis[j]=1;
		else v.push_back(make_pair(l,r));
	}
	for (int i=0;i<v.size();i++){
		int x=v[i].first,y=v[i].second;
		bool q=0;
		for (int j=x+1;j<=y;j++) if (!vis[j]) q=1;
		if (!q){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES\n";
	int now=5e8;
	cout<<now<<" ";
	for (int i=2;i<=n;i++){
		if (vis[i]) now++;
		else now--;
		cout<<now<<" ";
	}
}