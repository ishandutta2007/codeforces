#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int gett[maxn],nxt[maxn],fir[maxn],D[maxn];
int n,k,top,Ans;
inline void add(int x,int y){
	gett[++top]=y; nxt[top]=fir[x]; fir[x]=top;
}
int dfs(int x,int fa){
	vector<int> dsy;
	for (int i=fir[x];i;i=nxt[i]){
		int v=gett[i];
		if (v==fa) continue;
		dsy.push_back(dfs(v,x)+1);
	}
	sort(dsy.begin(),dsy.end());
	if (dsy.size()==0) return 0;
	for (int i=(int)dsy.size()-1;i>=1;--i)
	if (dsy[i]+dsy[i-1]<=k) return dsy[i]; else ++Ans;
	return dsy[0]; 
} 
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
		++D[x]; ++D[y];
	}
	for (int i=1;i<=n;++i)
	if (D[i]!=1){
		dfs(i,0);
		break;
	}
	printf("%d",Ans+1);
	return 0;
}