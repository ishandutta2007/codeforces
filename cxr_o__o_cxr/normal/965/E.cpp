#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=1e5+4;
int n,tot=1,ch[N][26],tag[N];
char s[N];
multiset<int>mu[N];
inline void insert(){
	int p=1,len=strlen(s+1);
	for(int i=1,c;i<=len;i++){
		c=s[i]-'a';
		if(!ch[p][c])ch[p][c]=++tot;
		p=ch[p][c];
	}
	tag[p]=1;
}
void dfs(int x,int dep){
	for(int i=0,v;i<26;i++){
		v=ch[x][i];
		if(!v)continue;
		dfs(v,dep+1);
		for(auto j:mu[v])mu[x].insert(j);//+1 
	}
	if(tag[x])mu[x].insert(dep);
	else if(x!=1){
		mu[x].erase(prev(mu[x].end()));
		mu[x].insert(dep);
	}
}
inline void out(int x){
	while(!mu[x].empty()){
		cout<<*mu[x].begin();
		mu[x].erase(mu[x].begin());
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		insert();
	} 
	dfs(1,0);
//	out(1);
	cout<<accumulate(mu[1].begin(),mu[1].end(),0);// 
	return (0-0);
}