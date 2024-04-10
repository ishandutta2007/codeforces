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

const int mod=1e9+7;
int fix(int x){
	return x>=mod?x-mod:x;
}

const int N=1e6+5;
namespace PAM{
	int t[N][26],fa[N],anc[N],len[N],d[N];
	int pos[N],sz,las;
	void init(char s[],int n){
		len[++sz]=-1,fa[1]=fa[0]=1;
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
}
using namespace PAM;

char s[N],st[N];
int f[N],g[N],n;

int main(){
	scanf("%s",st+1);
	n=strlen(st+1);
	for(int i=1,j=n,k=1;i<=j;i++,j--)
		s[k++]=st[i],s[k++]=st[j];
	init(s,n),f[0]=1;
	rep(i,1,n){
		for(int u=pos[i];len[u];u=anc[u]){
			g[u]=f[i-(len[anc[u]]+d[u])];
			if(d[u]==d[fa[u]]) g[u]=fix(g[u]+g[fa[u]]);
			if(!(i&1)) f[i]=fix(f[i]+g[u]);
		}
	}
	cout<<f[n]<<endl;
	return 0;
}