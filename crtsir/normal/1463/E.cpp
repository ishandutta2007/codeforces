#include<bits/stdc++.h>
using namespace std;
int n,k,p[300003],fa[300003],nxt[300003],x[300003],y[300003],cnt[300003];
vector<int>v[300003],g[300003],ans;
bool vis[300003];
int pos[300003];
int fnd(int X){
	if(X==fa[X])return X;
	fa[X]=fnd(fa[X]);
	return fa[X];
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){ 
		scanf("%d",p+i);p[i]--;
		fa[i]=i;nxt[i]=-1;
	}
	for(int i=0;i<k;i++){
		scanf("%d%d",x+i,y+i);
		x[i]--;y[i]--;
		fa[fnd(y[i])]=fnd(x[i]);
		nxt[x[i]]=y[i];
	}
	for(int i=0;i<n;i++)
		if(p[i]!=-1&&fnd(p[i])!=fnd(i)){
			v[fnd(p[i])].push_back(fnd(i));
			cnt[fnd(i)]++;
		}
	queue<int>Q;
	for(int i=0;i<n;i++)
		if(fa[i]==i&&cnt[i]==0)
			Q.push(i);
	while(Q.size()){
		int now=Q.front();Q.pop();
		int tmp=now;
		while(tmp!=-1){
			ans.push_back(tmp);
			if(vis[tmp]){cout<<0;return 0;}
			vis[tmp]=1;
			tmp=nxt[tmp];
		}
		for(int i=0;i<v[now].size();i++){
			cnt[v[now][i]]--;
			if(cnt[v[now][i]]==0)
				Q.push(v[now][i]);
		}
	}
	if(ans.size()!=n){cout<<0;return 0;}
	for(int i=0;i<n;i++)
		pos[ans[i]]=i;
	for(int i=0;i<n;i++)
		if(p[i]!=-1)
			if(pos[p[i]]>pos[i]){
				cout<<0;
				return 0;
			}
	for(int i=0;i<k;i++)
		if(pos[x[i]]!=pos[y[i]]-1){
			cout<<0;
			return 0;
		}
	for(int i=0;i<n;i++)
		printf("%d ",ans[i]+1);
}