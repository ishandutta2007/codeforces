#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
vector<int> E[MAXN];
bool cmp(int a,int b){
	return a<b;
}
priority_queue <int> pq;
int ans[MAXN],cd[MAXN];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i=0;i<m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		E[v].push_back(u);
		cd[u]++;
	}
	for (int i=1;i<=n;i++){
		if (cd[i]==0){
			pq.push(i);
		}
	}
	int now =n;
	while (!pq.empty()){
		int u = pq.top();
		ans[u] = now--;
		pq.pop();
		for (vector<int>::iterator it = E[u].begin();it!=E[u].end();it++){
			cd[(*it)]--;
			if (cd[(*it)]==0){
				pq.push((*it));
			}
		}
	}
	for (int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
}