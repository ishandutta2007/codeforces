// Thank to zhouyuyang. Copy from https://atcoder.jp/contests/arc115/submissions/24818457
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;
const int N=500005;
const int mo=998244353;
int n,a[N],q[N],l[N],r[N];
int f[N],g[N],s[N];
int main(){
	scanf("%d",&n);
	for (int i=2;i<=n+1;i++) scanf("%d",&a[i]);
	a[1]=a[n+2]=-(1<<30);
	int t=1; q[1]=1;
	for (int i=2;i<=n+2;i++){
		for (;t&&a[q[t]]>=a[i];--t)	r[q[t]]=i;
		l[i]=q[t]; q[++t]=i;
	}
	f[1]=1; s[1]=1;
	for (int i=2;i<=n+1;i++){
		f[i]=(s[i-1]+mo-s[l[i]-1])%mo;
		int val=1ll*a[i]*f[i]%mo;
		g[i]=(g[i]+g[i-1]+1ll*val)%mo;
		g[r[i]]=(g[r[i]]+mo-val)%mo;
		int vg=(i&1?mo-g[i]:g[i]);
		s[i]=(s[i-1]+mo-g[i])%mo;
		if (i==n+1) printf("%d\n",(vg+mo)%mo);
	}
}