#include<bits/stdc++.h>

using namespace std;
#define ll long long

namespace wish{
	int P1 = 998244853, P2 = 993244853, base = 2333333;
	int Pow(ll x, int y, const int P){
		int ans=1;
		for(; y; y>>=1, x=x*x%P) if(y&1) ans=ans*x%P;
		return ans;
	}
	struct Hash{
		int x, y;
		Hash(){}
		Hash(int a){ x=y=a;}
		Hash(int a, int b){ x=a, y=b;}
		Hash operator+(const Hash &r)const{
			return Hash((x+r.x)%P1, (y+r.y)%P2);
		}
		void operator+=(const Hash &r){
			(x+=r.x)%=P1, (y+=r.y)%=P2;
		}
		Hash operator-(const Hash &r)const{
			return Hash((x-r.x+P1)%P1, (y-r.y+P2)%P2);
		}
		void operator-=(const Hash &r){
			(x+=P1-r.x)%=P1, (y+=P2-r.y)%=P2;
		}
		Hash operator*(int r)const{ return Hash((ll)x*(r+P1)%P1, (ll)y*(r+P2)%P2);}
		Hash operator*(const Hash &r)const{
			return Hash((ll)x*r.x%P1, (ll)y*r.y%P2);
		}
		bool operator==(const Hash &r)const{ return x==r.x && y==r.y;}
		bool operator!=(const Hash &r)const{ return x!=r.x || y!=r.y;}
		Hash inv()const{ return Hash(Pow(x, P1-2, P1), Pow(y, P2-2, P2));}
		void print(){
			printf("[%d %d]\n", x, y);
		}
	};
	struct HashFunc{
		size_t operator()(const Hash &x)const{
			return hash<ll>()((ll)x.x<<32|x.y);
		}
	};
}
using namespace wish;

const int N = 200005;
int n, q, s[N], f[N], L[N], R[N];
char a[N];
Hash g[N], p[N], pp[N];
Hash calc(int l, int r){
	if(r-l+1==s[r]-s[l-1]) return Hash((r-l+1)&1);
	Hash ans=g[r]-g[l-1]*p[f[r]-f[l-1]];
	if(f[r]>f[l-1]) ans+=pp[f[r]-f[l-1]-1]*(s[l-1]-l+1);
	// ans.print();
	if(a[l-1]=='1' && a[l]=='1' && (R[l]-l+1)%2) ans+=p[f[r]-f[l-1]];
	if(a[r]=='1'){
		// printf(">> %d\n", r-l+1-s[r]+s[l-1]+1);
		if((R[r]-L[r]+1)%2 && !((r-L[r]+1)%2)) ans=(ans-(r-l+1-s[r]+s[l-1]+1))*Hash(base).inv();
		if(!((R[r]-L[r]+1)%2) && (r-L[r]+1)%2) ans=ans*base+(r-l+1-s[r]+s[l-1]+1);
	}
	return ans;
}
int main() {
	scanf("%d%s%d", &n, a+1, &q);
	p[0]=pp[0]=1;
	for(int i=1; i<=n; ++i) p[i]=p[i-1]*base, pp[i]=pp[i-1]+p[i];
	for(int i=1; i<=n; ++i) s[i]=s[i-1]+(a[i]=='1');
	for(int i=1; i<=n; ++i) if(a[i]=='1'){
		int j=i;
		while(a[j+1]=='1') ++j;
		if((j-i+1)&1) f[i]=i-s[i]+1;
		for(int k=i; k<=j; ++k) L[k]=i, R[k]=j;
		i=j;
	}
	for(int i=1; i<=n; ++i){
		if(f[i]) g[i]=g[i-1]*base+f[i], f[i]=f[i-1]+1;
		else f[i]=f[i-1], g[i]=g[i-1];
	}
	while(q--){
		int l1, l2, len;
		scanf("%d%d%d", &l1, &l2, &len);
		// calc(l2, l2+len-1).print();
		// assert(calc(l2, l2+len-1)==2);
		if(s[l2+len-1]-s[l2-1]!=s[l1+len-1]-s[l1-1] || calc(l1, l1+len-1)!=calc(l2, l2+len-1))
			puts("No");
		else puts("Yes");
	}
	return 0;
}