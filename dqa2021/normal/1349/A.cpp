#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector> 
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef long long ll;
ll qpow(ll x,ll y){
	ll res=1;
	for (;y;y>>=1,x*=x)
		if (y&1) res*=x;
	return res;
}

int n,W=2e5;
bool vis[200010]; int prm[200010],d[200010];
vector<int> c[200010];
int ins(int s,int t){
	c[s].push_back(t);
	return 0;
}
void work(int x){
	while (x^1){
		int s=d[x],t=0;
		while (x%s==0) x/=s,t++;
		ins(s,t);
	}
}
int main()
{
	for (int i=2;i<=W;i++){
		if (!vis[i]) prm[++*prm]=i,d[i]=i;
		for (int j=1;j<=*prm&&i*prm[j]<=W;j++){
			int t=i*prm[j]; vis[t]=1; d[t]=prm[j];
			if (i%prm[j]==0) break;
		}
	}
	
	n=read();
	for (int i=1;i<=n;i++) work(read());
	ll ans=1;
	for (int i=1;i<=*prm;i++){
		int x=prm[i];
		sort(c[x].begin(),c[x].end());
		if (n-c[x].size()>=2) continue;
		if (n-c[x].size()==1){ans*=qpow(x,c[x][0]); continue;}
		ans*=qpow(x,c[x][1]);
	}
	printf("%I64d\n",ans);
	return 0;
}