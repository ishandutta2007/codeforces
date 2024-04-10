#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int q[maxn][3];
vector<int> ext[maxn];
bool vis[maxn];
typedef pair<int,int> PII;
typedef vector<int> vi;
map<PII,vi> all;
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n-2;i++)
	{
		cin>>q[i][0]>>q[i][1]>>q[i][2];
		ext[q[i][0]].push_back(i);
		ext[q[i][1]].push_back(i);
		ext[q[i][2]].push_back(i);
		for(int k=0;k<3;k++){
			for(int j=k+1;j<3;j++){
				int u=q[i][k];
				int v=q[i][j];
				int zz=3-k-j;
				if(u>v) swap(u,v);
				if(!all.count(make_pair(u,v))) all[make_pair(u,v)]=vi();
				all[make_pair(u,v)].push_back(q[i][zz]);
			}
		}
	}
	vector<int> once,twice;
	for(int i=1;i<=n;i++){
		if(ext[i].size()==1) once.push_back(i);
		else if(ext[i].size()==2) twice.push_back(i);
	}
	vector<int> ans;
	ans.push_back(once[0]);
	vis[once[0]]=1;
	int cc=twice[0],zz=once[0];
	if(cc>zz) swap(cc,zz);
	if(all.count(make_pair(cc,zz))) ans.push_back(twice[0]);
	else ans.push_back(twice[1]);
	vis[ans[1]]=1;
	for(int i=2;i<n-1;i++){
		int u=ans[i-1],v=ans[i-2];
		if(u>v) swap(u,v);
		for(auto z:all[make_pair(u,v)]){
			if(!vis[z]){
				ans.push_back(z);
				vis[z]=1;
				break;
			}
		}
	}
	ans.push_back(once[1]);
	for(auto u:ans) cout<<u<<" ";
	cout<<endl;
}