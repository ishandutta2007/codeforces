#include<bits/stdc++.h>
using namespace std;
int n,m,k,a,b,col[200002],I[200002];vector<int>x[200002],y[200002];
int main(){
	cin>>n>>m>>k;for(int i=1;i<=n;i++)col[i]=-1;
	for(int i=1;i<=n;i++)cin>>I[i];
	for(int i=0;i<m;i++){
		cin>>a>>b;x[a].push_back(b);x[b].push_back(a);
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(col[i]>=0)continue;
		queue<int>Q;
		Q.push(i);col[i]=cnt;
		while(!Q.empty()){
			int a1=Q.front();Q.pop();
			for(int j:x[a1]){if(col[j]==-1){col[j]=cnt;Q.push(j);}}
		}
		cnt++;
	}
	for(int i=1;i<=n;i++)y[col[i]].push_back(i);
	int V=0;
	for(int i=0;i<cnt;i++){
		map<int,int>M;
		for(int j:y[i])M[I[j]]++;
		int maxn=9999999;
		for(int j:y[i])maxn=min(maxn,(int)y[i].size()-M[I[j]]);
		V+=maxn;
	}
	cout<<V<<endl;
	return 0;
}