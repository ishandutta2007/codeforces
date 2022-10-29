// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back

using namespace std;
typedef long long ll;

template <typename T> void rd(T &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
void wr(ll x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}

// ---------- IO ---------- //

const int N=2e5+5,G=1005;
int n,m,cnt,mex[N],hd[N],g;
bool vst[N],qaq[G],del[G];
ll sum[G],h[N];

struct edge{int t,nxt;}e[N];
inline void add(int x,int y){e[++cnt]=(edge){y,hd[x]};hd[x]=cnt;}

vector<int> topo;

bool dfs(int x){
	vst[x]=-1;
	for(re i=hd[x];i;i=e[i].nxt){
		if(vst[e[i].t]==-1) return 0;
		if(vst[e[i].t]==0) if(!dfs(e[i].t)) return 0;
	}
	vst[x]=1;
	topo.push_back(x);
	return 1;
}

inline void toposort(){
	for(re i=1;i<=n;i++) if(!vst[i]) dfs(i);
//	reverse(topo.begin(),topo.end());
}

// ---------- toposort ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);rd(m);
	for(re i=1;i<=n;i++) rd(h[i]);
	for(re i=1;i<=m;i++){
		int u,v;rd(u);rd(v);
		add(u,v);
	}
	toposort();
	for(re i=0;i<n;i++){
		int nw=topo[i];
		for(re j=hd[nw];j;j=e[j].nxt) qaq[mex[e[j].t]]=1;
		while(qaq[mex[nw]]) mex[nw]++;g=max(g,mex[nw]);
		sum[mex[nw]]^=h[nw];
		for(re j=hd[nw];j;j=e[j].nxt) qaq[mex[e[j].t]]=0;
	}
	for(re i=g;i>=0;i--)
		if(sum[i]){
			puts("WIN");
			for(re j=1;j<=n;j++)
				if(mex[j]==i&&(h[j]^sum[i])<h[j]){
					h[j]^=sum[i];del[i]=1;
					for(re k=hd[j];k;k=e[k].nxt)
						if(sum[mex[e[k].t]]&&!del[mex[e[k].t]]) h[e[k].t]^=sum[mex[e[k].t]],del[mex[e[k].t]]=1;
					break;
				}
			for(re j=1;j<=n;j++) wr(h[j]),putchar(' ');puts("");
			return 0;
		}
	puts("LOSE");
	return 0;
}

// ---------- Main ---------- //