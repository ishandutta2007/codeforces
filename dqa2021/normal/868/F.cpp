#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
typedef long long ll;
const ll INF=1e18;

int n,k,w[100010];

int cl,cr,bin[100010]; ll res;
ll calc(int l,int r){
	while (l<cl) res+=(bin[w[--cl]]++);
	while (cr<r) res+=(bin[w[++cr]]++);
	while (cl<l) res-=(--bin[w[cl++]]);
	while (r<cr) res-=(--bin[w[cr--]]);
	return res;
}
ll dp[25][100010];
void solve(int id,int l,int r,int L,int R){
	int mid=l+r>>1;
	dp[id][mid]=INF; ll tmp; int maxid;
	for (int i=L;i<=R&&i<mid;i++){
		tmp=dp[id-1][i]+calc(i+1,mid);
		if (tmp<dp[id][mid]) dp[id][mid]=tmp,maxid=i;
	}
	if (l<mid) solve(id,l,mid-1,L,maxid);
	if (mid<r) solve(id,mid+1,r,maxid,R);
}

int main()
{
	n=read(),k=read();
	for (int i=1;i<=n;i++) w[i]=read();
	cl=cr=1,bin[w[1]]++,res=0;
	for (int i=1;i<=n;i++) dp[1][i]=calc(1,i);
	for (int i=2;i<=k;i++) solve(i,i,n,i-1,n);
	printf("%I64d\n",dp[k][n]);
	return 0;
}