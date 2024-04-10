#include<bits/stdc++.h>
#define int long long
const int N=300005;
using namespace std;

int n,a[N];
queue<int> p[N];
vector<int> ans;

void solve(){
	cin>>n;
	ans.clear();
	for(int i=0;i<=n;i++)
		while(p[i].size())p[i].pop();
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[a[i]].push(i);
	}
	for(int px=0;px<n;){
		int mx=px+1,id=-1;
		for(int j=0;j<=n;j++){
			while(!p[j].empty()&&p[j].front()<=px)p[j].pop();
			if(p[j].empty())break;
			mx=max(mx,p[j].front());
			id=j;
		}
		px=mx,ans.push_back(id+1);
	}
	cout<<ans.size()<<endl;
	for(auto x:ans)cout<<x<<' ';cout<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}