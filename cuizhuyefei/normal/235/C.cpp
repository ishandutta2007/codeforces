#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 2020000;
char s[N];bool vis[N];int sta[N],top;ll res;
int ch[N][26],fa[N],size[N],Max[N],lst=1,cnt=1;
inline void ins(int c){
	int p=lst,np=++cnt;lst=np;Max[np]=Max[p]+1;
	for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
	if(!p)fa[np]=1;
	else{
		int q=ch[p][c];
		if (Max[q]==Max[p]+1)fa[np]=q;
		else{
			int nq=++cnt;Max[nq]=Max[p]+1;
			memcpy(ch[nq],ch[q],104);
			fa[nq]=fa[q];fa[q]=fa[np]=nq;
			for(;p&&ch[p][c]==q;p=fa[p])ch[p][c]=nq;
		}
	}
	size[np]++;
}
inline void init(){
	static int buc[N],s[N];
	per(i,cnt,1)buc[Max[i]]++;
	rep(i,1,cnt)buc[i]+=buc[i-1];
	per(i,cnt,1)s[buc[Max[i]]--]=i;
	per(i,cnt,1)size[fa[s[i]]]+=size[s[i]];size[1]=0;//size[1]?????
}
inline void add(int &p, int &len, int c){
	for(;p>1&&!ch[p][c];p=fa[p],len=Max[p]);
	p=ch[p][c]?len++,ch[p][c]:p;
}
inline void find(int p){
	sta[++top]=p; res+=!vis[p]?vis[p]=1,size[p]:0;
}
int main() { //freopen("1.in","r",stdin);
	scanf("%s",s+1);int n=strlen(s+1);rep(i,1,n)ins(s[i]-'a');
	init();int q;read(q);while (q--){
		scanf("%s",s+1);n=strlen(s+1);res=0;
		int now=1,len=0;rep(i,1,n)add(now,len,s[i]-'a');
		if(len==n)find(now);
		rep(i,1,n-1){
			if(len==n){len--;if(len==Max[fa[now]])now=fa[now];}
			add(now,len,s[i]-'a'); if(len==n)find(now);
		}
		printf("%lld\n",res);while(top)vis[sta[top--]]=0;
	}
	return 0;
}