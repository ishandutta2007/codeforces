#include<bits/stdc++.h>
#define N 201000
using namespace std;

struct node
{
	int op;
	long long w;
	
	/*   node{} */  /*node a =  b; */ // ?? ?? 
//	node()
//	{
//		op=0;
//		w=0;
//	}
	
	bool operator < (const node & a)const
	{
		if(w!=a.w)return w<a.w;
		return op<a.op; //vector zhiyong diyihang
	}
};
set<node>S;
int n, m;
long long D[N];
vector<int>E[N];
vector<long long>L[N];
void Put(int a, long long d) {
	if (D[a] <= d)return;
	S.erase((node){a,D[a]});
	D[a] = d;
	S.insert((node){a,d});
}
int main() {
	int i, a, b;
	long long c;
	scanf("%d%d", &n,&m);
	for (i = 0; i < m; i++) {
		scanf("%d%d%I64d", &a, &b, &c);
		E[a].push_back(b);
		L[a].push_back(2ll*c);
		E[b].push_back(a);
		L[b].push_back(2ll*c);
	}
	for (i = 1; i <= n; i++)D[i] = 5e18;
	for (i = 1; i <= n; i++) {
		scanf("%I64d", &c);
		Put(i, c);
	}
	while (!S.empty()) {
		node tp = *(S.begin());  
		S.erase(tp);
		int x = tp.op;
		if (D[x] != tp.w)continue;
		//.size()  //O1??
		for (i = 0; i < E[x].size(); i++) Put(E[x][i], D[x] + L[x][i]);
	}
	for (i = 1; i <= n; i++)printf("%I64d ", D[i]);
}