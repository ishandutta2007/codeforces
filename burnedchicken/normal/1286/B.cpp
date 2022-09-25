#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) loopii(i,0,a)
#define loopii(i,b,a) for(int i=b; i<(a); i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	int pre[n+1],c[n+1],num[n+1];
	vector<int> child[n+1];
	int root;
	loop(n) num[i+1]=0;
	loop(n){
		cin >> pre[i+1] >> c[i+1];
		child[pre[i+1]].push_back(i+1);
		if(pre[i+1]==0) root=i+1;
		else num[pre[i+1]]++;
	}
	vector<int> vec[n+1];
	vector<int>::iterator it;
	queue<int> q;
	loop(n) if(num[i+1]==0) q.push(i+1);
	int x;
	while(!q.empty()){
		x=q.front();
		loop(child[x].size()){
			loopi(j,vec[child[x][i]].size()) vec[x].push_back(vec[child[x][i]][j]);
			vec[child[x][i]].clear();
		}
		if(c[x]>vec[x].size()){
			cout << "NO\n";
			return 0;
		}
		it=vec[x].begin();
		if(c[x]==vec[x].size()) vec[x].push_back(x);
		else vec[x].insert(it+c[x],x);
		num[pre[x]]--;
		if(num[pre[x]]==0) q.push(pre[x]);
		q.pop();
	}
	int ans[n+1];
	loop(n) ans[vec[root][i]]=i+1;
	cout << "YES\n";
	loop(n) cout << ans[i+1] << ' ';
	cout << "\n";
	return 0;
}