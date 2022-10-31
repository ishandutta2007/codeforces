#include<bits\stdc++.h>
#define LL long long
#define mp make_pair
#define pii pair<int,int>
#define sp set<pii >
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=200005;
int n,g,r,l[Maxn],t[Maxn],firsp[Maxn],ficost[Maxn],dur,q;
LL sum[Maxn],ans[Maxn],cost[Maxn];
sp qu;
int main(){
	n=read();g=read();r=read();
	dur=g+r;
	for (int i=1;i<=n+1;i++){
		l[i]=read();
		sum[i]=sum[i-1]+l[i];
	}
	for (int i=0;i<Maxn;i++) firsp[i]=-1;
	scanf("%d",&q);
	for (int i=1;i<=q;i++){
		t[i]=read();ans[i]=sum[n+1]+t[i];qu.insert(mp(t[i]%dur,i));
	}
	for (int i=1;i<=n;i++){
		int now=sum[i]%dur;
		pii tmp=mp(g-now,-1);
		sp ::iterator it=qu.lower_bound(tmp),it2;
		while (it!=qu.end()){
			if ((it->first+now)%dur<g) break;
			firsp[it->second]=i;
			ficost[it->second]=dur-((it->first+now)%dur);
			it2=it++;
			qu.erase(it2);
		}
		if (g<now){
			tmp=mp(g-now+dur,-1);
			it=qu.lower_bound(tmp);
			while (it!=qu.end()){
				if ((it->first+now)%dur<g) break;
				firsp[it->second]=i;
				ficost[it->second]=dur-((it->first+now)%dur);
				it2=it++;
				qu.erase(it2);
			}
		}
		qu.insert(mp(((-sum[i])%dur+dur)%dur,q+i));
	}
	for (int i=n;i>=1;i--){
		cost[i]=(firsp[i+q]==-1)?0:(ficost[i+q]+cost[firsp[i+q]]);
	}
	for (int i=1;i<=q;i++){
		ans[i]+=ficost[i];
		if (firsp[i]!=-1) ans[i]+=cost[firsp[i]];
		printf("%I64d\n",ans[i]);
	}
}