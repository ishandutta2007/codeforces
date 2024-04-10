#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int S=1e5+5,N=2e6+6,P=1e9+7; 
int pw[N],inv[N],c[S][30],a[N],b[N],l,nxt[N];
char s0[N],t[N],w[N];
void trans(int c,int &p,int &s){
	while (p&&b[p+1]!=c) p=nxt[p];
	if (b[p+1]==c) ++p; if (p==l) ++s,p=nxt[p];
}
void KMP(int n,int &p,int &s){ 
	rep(i,1,n) trans(a[i],p,s); 
}
int main(){
	int n,q; scanf("%d%d%s%s",&n,&q,s0,t);
	int m0=strlen(s0); 
	pw[0]=1; rep(i,1,n) pw[i]=2LL*pw[i-1]%P;
	inv[0]=1; rep(i,1,n) inv[i]=(ll)(P+1)/2*inv[i-1]%P;
	rep(i,1,n)
		rep(j,1,26){
			c[i][j]=c[i-1][j];
			if (t[i-1]-'a'+1==j) c[i][j]=(c[i][j]+inv[i])%P;
		}
	while (q--){
		int k; scanf("%d%s",&k,w); l=strlen(w);
		rep(i,1,l) b[i]=w[i-1]-'a'+1;
		for (int i=2,j=0;i<=l;++i){
			while (j&&b[i]!=b[j+1]) j=nxt[j];
			if (b[i]==b[j+1]) ++j; nxt[i]=j;
		}
		int m=m0; rep(i,1,m) a[i]=s0[i-1]-'a'+1;
		int j=1;
		for (;m<l&&j<=n;++j,m=2*m+1){
			a[m+1]=t[j-1]-'a'+1;
			rep(i,1,m) a[m+1+i]=a[i];
		}
		if (m<l){ puts("0"); continue; }
		--j; if (j>k){ puts("0"); continue; }
		int s=0,p=0; KMP(m,p,s);
		int ans=(ll)pw[k-j]*s%P;
		rep(ch,1,26)
			if (c[k][ch]-c[j][ch]){
				int d=0,p2=p; trans(ch,p2,d),KMP(l-1,p2,d);
				ans=(ans+(ll)pw[k]*(c[k][ch]+P-c[j][ch])%P*d)%P;
			}
		printf("%d\n",ans);
	}
	return 0;
}