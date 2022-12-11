#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])
const int INF=1e5+5;
int qpow(int x,int y){
	int res=1;
	while (y){
		if (y&1){
			if (res>INF/x) return INF;
			res*=x;
		}
		y>>=1;
		if (!y) break;
		if (x>INF/x) x=INF;
		else x*=x;
	}
	return res;
}

int n,m=1e5,k;
int c[100010];

int work(int x){
	static int p[110],c[110]; int top=0;
	for (int i=2;i*i<=x;++i)
		if (x%i==0){
			p[++top]=i,c[top]=0;
			while (x%i==0) x/=i,++c[top];
		}
	if (x^1) p[++top]=x,c[top]=1;
	int z=1;
	rep(i,1,top){
		if (c[i]%k==0) continue;
		c[i]%=k;
		int w=qpow(p[i],k-c[i]);
		if (z>INF/w) return INF;
		z*=w;
	}
	return z;
}

void solve(){
	n=read(),k=read();
	rep(i,1,n) ++c[read()];
	ll z=0;
	rep(i,1,m){
		int t=work(i);
		if (t>m) continue;
		//if (c[i]) printf("t %d = %d\n",i,t);
		int lim=pow(m/t,1.0/k)+1e-8;
		rep(j,1,lim){
			const int w=t*qpow(j,k);
			if (w==i) z+=1LL*c[i]*(c[i]-1)/2;
			if (w<=i) continue;
			z+=1LL*c[i]*c[w];
			//if (c[i]&&c[w]) printf("check %d %d\n",i,w);
		}
	}
	/*rep(i,1,m){
		int t=pow(i,1.0/k);
		if (qpow(t,k)!=i) continue;
		z+=1LL*c[i]*(c[i]-1)/2;
	}*/
	printf("%lld\n",z);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}