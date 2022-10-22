#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> v[100009];
bool preso[100009];
int fatti=0;
void dfs(int pos){
	for(int i=0;i<v[pos].size();i++){
		if(preso[v[pos][i]]==0){
			preso[v[pos][i]]=1;
			fatti++;
			dfs(v[pos][i]);
		}
	}
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		int N,K;
		cin>>N>>K;
		for(int i=0;i<K;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(int i=1;i<=N;i++){
			if(preso[i])continue;
			preso[i]=1;
			dfs(i);
		}
		cout<<K-fatti;
		return 0;
}