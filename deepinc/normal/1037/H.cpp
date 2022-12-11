#include<bits/stdc++.h>
using namespace std;
const int S=2e5+3;
int f[S],c[S][26],len[S],rt[S],pc,lc[S<<7],rc[S<<7],Q,n,lst=1,Pc=1,to[S]; char s[S];
vector<int>v[S];
#define md (L+R>>1)
void ins(int&p,int x,int L=1,int R=n){
	p=++pc; if(L==R)return;
	if(x<=md)ins(lc[p],x,L,md);else ins(rc[p],x,md+1,R);
}
void extend(int C){
	int p=lst,np=lst=++Pc,q,nq; len[np]=len[p]+1; ins(rt[np],len[np]);
	for(;p&&!c[p][C];p=f[p])c[p][C]=np;
	if(!p){f[np]=1;return;}
	if(len[q=c[p][C]]==len[p]+1){f[np]=q;return;}
	nq=++Pc; len[nq]=len[p]+1; f[nq]=f[q]; f[q]=f[np]=nq;
	for(int i=0;i<26;++i)c[nq][i]=c[q][i];
	for(;c[p][C]==q;p=f[p])c[p][C]=nq;
}
int merge(int p,int c){
	if(!p||!c)return p|c;
	int x=++pc;lc[x]=merge(lc[p],lc[c]);rc[x]=merge(rc[p],rc[c]);return x;
}
void dfs(int p){for(auto x:v[p])dfs(x),rt[p]=merge(rt[p],rt[x]);}
int ask(int p,int l,int r,int L=1,int R=n){
	if(!p)return 0; if(l<=L&&R<=r)return 1;
	return (l<=md?ask(lc[p],l,r,L,md):0)||(r>md?ask(rc[p],l,r,md+1,R):0);
}
int main(){
	scanf("%s%d",s,&Q); n=strlen(s);
	for(int i=0;s[i];++i)extend(s[i]-'a');
	for(int i=2;i<=Pc;++i)v[f[i]].push_back(i);
	dfs(1); 
	for(int _=1,l,r;_<=Q;++_){
		scanf("%d%d%s",&l,&r,s); int i=0,p=1;
		for(;;++i){
			to[i]=-1;
			for(int j=max(0,s[i]-'a'+1);j<26&&to[i]==-1;++j)if(ask(rt[c[p][j]],l+i,r))to[i]=j;
			if(!s[i]||!ask(rt[c[p][s[i]-'a']],l+i,r))break; p=c[p][s[i]-'a'];
		}while(~i&&to[i]==-1)i--;
		if(i<0)puts("-1");
		else{for(int j=0;j<i;++j)putchar(s[j]);printf("%c\n",'a'+to[i]);}
	}
}