#include<bits/stdc++.h>
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
const int N = 1010000, M = 21000000, inf = 0x3f3f3f3f;
int n;char s[N];
int ch[N][26],lst=1,cnt=1,Max[N],fa[N],rt[N],lc[M],rc[M],mn[M],sz,node[N],f[N];
inline void build(int &k, int p, int l, int r){
	k=++sz;mn[k]=p;if(l==r)return;int mid=(l+r)>>1;
	if(p<=mid)build(lc[k],p,l,mid);else build(rc[k],p,mid+1,r);
}
inline int merge(int k1, int k2, int l, int r){
	if(!k1||!k2)return k1+k2;int o=++sz,mid=(l+r)>>1;
	lc[o]=merge(lc[k1],lc[k2],l,mid);
	rc[o]=merge(rc[k1],rc[k2],mid+1,r);
	mn[o]=min(mn[lc[o]],mn[rc[o]]);return o;
}
inline void ins(int c, int pos){
	int p=lst,np=++cnt;lst=np;Max[np]=Max[p]+1;
	for(;p&&!ch[p][c];p=fa[p])ch[p][c]=np;
	if(!p)fa[np]=1;
	else{
		int q=ch[p][c];
		if(Max[p]+1==Max[q])fa[np]=q;
		else{
			int nq=++cnt;Max[nq]=Max[p]+1;
			fa[nq]=fa[q];fa[q]=fa[np]=nq;
			memcpy(ch[nq],ch[q],104);
			for(;ch[p][c]==q;p=fa[p])ch[p][c]=nq;
		}
	}
	build(rt[np],pos,1,n);node[pos]=np;
}
inline void init(){
	/*rep(i,1,cnt){
		printf("%d:%d %d\n",i,Max[i],fa[i]);
		rep(j,0,25)if(ch[i][j])printf("ch[%d][%c]=%d\n",i,'a'+j,ch[i][j]);
	}*/
	static int buc[N],s[N];
	rep(i,1,cnt)buc[Max[i]]++;
	rep(i,1,cnt)buc[i]+=buc[i-1];
	rep(i,1,cnt)s[buc[Max[i]]--]=i;
	per(i,cnt,1){int u=s[i],f=fa[u];rt[f]=merge(rt[f],rt[u],1,n);}
}
inline int find(int k, int p, int l, int r){//max{<=p}
	if(!k)return 0;if(l==r)return mn[k];int mid=(l+r)>>1;
	if(mn[rc[k]]<=p)return find(rc[k],p,mid+1,r);
	return find(lc[k],p,l,mid);
}
inline bool ck(int l, int r, int lim, int u){
	int p=find(rt[u],lim,1,n);return p>=1&&p<=lim&&f[p]>=r-l+1;
}
int main() {
	scanf("%d",&n);scanf("%s",s+1);reverse(s+1,s+n+1);memset(mn,inf,sizeof(mn));
	rep(i,1,n)ins(s[i]-'a',i);init();//rep(i,1,n)printf("[%d %d]\n",node[i],mn[rt[node[i]]]);
	f[1]=1;for(int i=2,j=1,p1=node[2],p2=node[1];i<=n;i++,p1=ch[p1][s[i]-'a'],p2=ch[p2][s[i-1]-'a']){//WA
		while(i-j+1>1){
			while(Max[fa[p1]]+1>i-j)p1=fa[p1];
			while(Max[fa[p2]]+1>i-j)p2=fa[p2];
		//	if(i==5&&j==4)printf("GG %d %d\n",p1,p2);
			if(ck(j+1,i,j-1,p1)||ck(j,i-1,j-1,p2))break;j++;
		}
	//	printf("%d %d\n",i,j);
		f[i]=i-j+1;
	}
	int res=0;rep(i,1,n)res=max(res,f[i]);cout<<res;
	return 0;
}