#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 3005
#define mo 998244353
#define ll long long
using namespace std;

int n,c,i,j,k,a[maxn];
int cnt[maxn],nex[maxn][maxn];
ll _2[maxn],mul,inv[maxn],ans[maxn],f[maxn][maxn];

void read(int &x){
	x=0; char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
}

ll ksm(ll x,ll y){
	ll s=1;
	for(;y;y/=2,x=x*x%mo) if (y&1)
		s=s*x%mo;
	return s;
}

void prepare(){
	for(i=2;i<=n;i++){
		memcpy(nex[i],nex[i-1],sizeof(nex[i]));
		nex[i][a[i-1]]=i-1;
	}
//	for(i=n-1;i>=1;i--){
//		memcpy(nex[i],nex[i+1],sizeof(nex[i]));
//		nex[i][a[i+1]]=i+1;
//	}
	for(_2[0]=1,i=1;i<=n;i++) _2[i]=_2[i-1]*2%mo;
	inv[0]=1;
	for(i=1;i<=n;i++) inv[i]=ksm(_2[i]-1,mo-2);	
}

void Doit1(){
	f[0][0]=1;
	for(i=1;i<=n;i++){
		int st=i;
		for(j=1;j<=c;j++) if (j!=a[i])
			st=min(st,nex[i][j]);
		if (!st) continue;
		memset(cnt,0,sizeof(cnt));
		for(j=i-1;j>=st;j--) cnt[a[j]]++;
		ll mul=1;
		for(j=1;j<=c;j++) if (j!=a[i])
			mul=mul*(_2[cnt[j]]-1)%mo;
		for(j=st;j>0;j--){
			for(k=1;k<=i/c;k++) f[i][k]+=f[j-1][k-1]*mul%mo;
			if (j>1&&a[j-1]!=a[i]) {
				mul=mul*inv[cnt[a[j-1]]]%mo;
				mul=mul*(_2[++cnt[a[j-1]]]-1)%mo;
			}
		}
		for(k=1;k<=i/c;k++) f[i][k]%=mo;
	}
	memset(cnt,0,sizeof(cnt));
	for(i=n;i>=1;i--){
		if (i<n) cnt[a[i+1]]++;
		ll mul=1;
		for(j=1;j<=c;j++) mul=mul*(_2[cnt[j]]-1)%mo;
		for(j=1;j<=i/c;j++){
			f[i][j]=f[i][j]*((_2[n-i]-mul+mo)%mo)%mo;
			ans[0]+=f[i][j];
			ans[j]+=f[i][j];
		}
	}
	printf("%I64d ",(_2[n]-1-ans[0]%mo+mo)%mo);
	for(i=1;i<=n;i++) printf("%I64d ",ans[i]%mo);	
}

ll g[2][maxn][1<<10];
void Doit2(){
	g[0][0][0]=1;
	for(i=1;i<=n;i++){
		int p=i&1,q=p^1;
		for(j=0;j<=i/c;j++) for(int S=0;S<1<<c;S++)
			g[p][j][S]=g[q][j][S];
		for(j=0;j<=(i-1)/c;j++) for(int S=0;S<1<<c;S++)	if (g[q][j][S]){
			int T=S|_2[a[i]-1],t=j;
			if (T==_2[c]-1) t++,T=0;
			g[p][t][T]+=g[q][j][S];
			if (g[q][t][T]>1e15) g[p][t][T]%=mo;
		}
	}
	for(i=0;i<=n/c;i++) for(int S=0;S<1<<c;S++)
		ans[i]+=g[n&1][i][S]%mo;
	ans[0]--;
	for(i=0;i<=n;i++)
		printf("%I64d ",ans[i]%mo);
}

int main(){
	read(n),read(c);
	for(i=1;i<=n;i++) read(a[i]);
	prepare();
	if (c>10) Doit1();
	else Doit2();
}