#include<bits/stdc++.h>
#define ll long long
#define N 300003
using namespace std;
int ST[N],ED[N],dfn,Ans;
vector<int>v1[N],v2[N];
struct cmp{
	bool operator ()(const int a,const int b)const{
		return (ST[a]<ST[b]);
	}
};
set<int,cmp>S;
void DFS1(int x){
	ST[x]=++dfn;
	for(int i=0;i<v2[x].size();++i)DFS1(v2[x][i]);
	ED[x]=++dfn;
}
void DFS2(int x){
	auto nxt=S.upper_bound(x);
	int A=0,B=0;
	if(nxt!=S.begin()&&ED[*prev(nxt)]>=ED[x])A=*prev(nxt);
	if(nxt==S.end()||ED[*nxt]>=ED[x])B=x;
	if(A)S.erase(A);
	if(B)S.insert(B);
	Ans=max(Ans,(int)S.size());
	for(int i=0;i<v1[x].size();++i)DFS2(v1[x][i]);
	if(B)S.erase(B);
	if(A)S.insert(A);
}
int main(){
	int n,T,i,j,x;
	scanf("%d",&T);while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;++i){
			v1[i].clear();
			v2[i].clear();
		}
		for(i=2;i<=n;++i){
			scanf("%d",&x);
			v1[x].push_back(i);
		}
		for(i=2;i<=n;++i){
			scanf("%d",&x);
			v2[x].push_back(i);
		}
		dfn=0;DFS1(1);
		Ans=0;DFS2(1);
		printf("%d\n",Ans);
	}
	return 0;
}