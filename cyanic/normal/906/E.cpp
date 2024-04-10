#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=1e6+5;
namespace PAM{
	int t[N][26],fa[N],anc[N],len[N],d[N];
	int pos[N],sz,las,n;
	char *s;
	void init(char s[],int n){
		len[++sz]=-1,PAM::n=n,PAM::s=s;
		fa[1]=fa[0]=anc[0]=1;
		rep(i,1,n){
			int p=las,c=s[i]-'a';
			for(;s[i-1-len[p]]!=s[i];p=fa[p]);
			if(!t[p][c]){
				int nw=++sz,q=fa[p];
				for(;s[i-1-len[q]]!=s[i];q=fa[q]);
				len[nw]=len[p]+2;
				fa[nw]=t[q][c],t[p][c]=nw;
				d[nw]=len[nw]-len[fa[nw]];
				anc[nw]=(d[nw]==d[fa[nw]]?anc[fa[nw]]:fa[nw]);
			}
			pos[i]=las=t[p][c];
		}
	}
	int f[N],g[N],p[N];
	void solve(){
		memset(f,0x3f,sizeof f);
		f[0]=0,g[0]=n;
		rep(i,1,n){
			for(int u=pos[i];len[u]>0;u=anc[u]){
				g[u]=i-len[anc[u]]-d[u];
				if(d[u]==d[fa[u]]&&f[g[fa[u]]]<f[g[u]]) g[u]=g[fa[u]];
				if(!(i&1)&&f[g[u]]+1<f[i]) f[i]=f[g[u]]+1,p[i]=g[u];
			}
			if(!(i&1)&&s[i]==s[i-1]&&f[i-2]<f[i]) f[i]=f[i-2],p[i]=i-2;
		}
		if(f[n]>1e9){
			puts("-1");
			return;
		}
		printf("%d\n",f[n]);
		for(int k=n;k;k=p[k])
			if(k-p[k]>2) printf("%d %d\n",p[k]/2+1,k/2);
	}
}

char s[N],t[N],st[N];
int n;

int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	rep(i,1,n) st[i*2-1]=s[i],st[i*2]=t[i];
	PAM::init(st,n*2);
	PAM::solve();
	return 0;
}