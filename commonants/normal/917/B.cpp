#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
const int MX=105,MXA=27;

vector<pii>G[MX];
char sta[MX][MX][MXA];int n,m;
//s[i][j][k]:A(first)->i B(second)->j last=k

char F(int A,int B,int l){
	if(sta[A][B][l])return sta[A][B][l];
	for(auto i:G[A])if(i.second>=l){
		if(F(B,i.first,i.second)==-1)return sta[A][B][l]=1;
	}
	return sta[A][B][l]=-1;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;char c;
		cin>>u>>v>>c;
		c-='a';
		G[u].push_back(make_pair(v,(int)c));
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<(F(i,j,0)==1?'A':'B');
		cout<<endl;
	}
	return 0;
}