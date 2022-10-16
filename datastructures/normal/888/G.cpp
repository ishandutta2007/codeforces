#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
struct trie_node{
	int son[2],sz;
	trie_node(){
		son[0]=son[1]=0;
		sz=0;
		return;
	}
}trie[10000005];
int cnt;
int n,a[200005];
ll ans;
void ins(int x){
	int now=0;
	for (int i=30;i>=0;i--){
		int trans=0;
		if (x&(1<<i))trans=1;
		if (trie[now].son[trans]==0)trie[now].son[trans]=++cnt;
		now=trie[now].son[trans];
		trie[now].sz++;
	}
	return;
}
int calc(int x,int y,int val){
	if (val==0)return 0;
	int ans=2e9;
	if (trie[x].son[0]!=0){
		if (trie[y].son[0]!=0)ans=min(ans,calc(trie[x].son[0],trie[y].son[0],val/2));
		else ans=min(ans,val+calc(trie[x].son[0],trie[y].son[1],val/2));
	}
	if (trie[x].son[1]!=0){
		if (trie[y].son[1]!=0)ans=min(ans,calc(trie[x].son[1],trie[y].son[1],val/2));
		else ans=min(ans,val+calc(trie[x].son[1],trie[y].son[0],val/2));
	}
	return ans;
}
void dfs(int now,int val){
	if (trie[now].son[0])dfs(trie[now].son[0],val/2);
	if (trie[now].son[1])dfs(trie[now].son[1],val/2);
	if (trie[now].son[0]&&trie[now].son[1]){
		int x=trie[now].son[0],y=trie[now].son[1];
		ans+=val+calc(x,y,val/2);
	}
	return;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)a[i]=read();
	for (int i=1;i<=n;i++)ins(a[i]);
	dfs(0,(1<<30));
	cout<<ans<<endl;
	return 0;
}