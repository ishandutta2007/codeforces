#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int cnt,q,lst,cur;
int s[1000004];int it,n,ans;
int ch[1000004][26],num[1000004];
int nx[1000004],le[1000004];
int fa[1000004],tg[1000004];
vector<int>vec[1000004];
int get(int x,int p){
	while(p-le[x]-1<0||s[p-le[x]-1]!=s[p])x=nx[x];
	return x;
}
void push(char c){
	++n,s[n]=c,cur=get(cur,n);bool now=0;
	if(!ch[cur][c]){
		int p=++cnt;int q=nx[p]=ch[get(nx[cur],n)][c];
		ch[cur][c]=p,fa[p]=cur;
		num[q]++,le[p]=le[cur]+2;now=1;++ans;
	}
	cur=ch[cur][c],tg[cur]=n;
	if(!num[cur])vec[n-le[cur]+1].push_back(cur);
}
void pop(){
	++it,s[it]=-1;int p=-1;
	for(auto x:vec[it])if(!num[x]&&it==tg[x]-le[x]+1)p=x;
	if(~p){
		for(int c=0;c<26;c++)if(ch[fa[p]][c]==p)ch[fa[p]][c]=0;
		--ans;int q=nx[p];num[q]--,tg[q]=max(tg[q],tg[p]);
		if(!num[q]&&q>1)vec[tg[q]-le[q]+1].push_back(q);
		if(cur==p)cur=q;
	}
}
int main(){
	scanf("%d",&q);
	cnt=1,nx[0]=1,le[1]=-1,s[0]=-1;
	while(q--){
		char buf[10],ch[10];
		scanf("%s",buf);
		if(buf[1]=='u')scanf("%s",ch),push(ch[0]-'a');
		else pop();
		printf("%d\n",ans);
	}
}