#include<bits/stdc++.h>
using namespace std;
template<const int mod>
struct modint{
    int x;
    modint<mod>(int o=0){x=(o+mod)%mod;}
    modint<mod> &operator = (int o){return x=o,*this;}
    modint<mod> &operator +=(modint<mod> o){return x=x+o.x>=mod?x+o.x-mod:x+o.x,*this;}
    modint<mod> &operator -=(modint<mod> o){return x=x-o.x<0?x-o.x+mod:x-o.x,*this;}
    modint<mod> &operator *=(modint<mod> o){return x=1ll*x*o.x%mod,*this;}
    modint<mod> &operator ^=(int b){
        modint<mod> a=*this,c=1;
        for(;b;b>>=1,a*=a)if(b&1)c*=a;
        return x=c.x,*this;
    }
    modint<mod> &operator /=(modint<mod> o){return *this *=o^=mod-2;}
    modint<mod> &operator +=(int o){return x=x+o>=mod?x+o-mod:x+o,*this;}
    modint<mod> &operator -=(int o){return x=x-o<0?x-o+mod:x-o,*this;}
    modint<mod> &operator *=(int o){return x=1ll*x*o%mod,*this;}
    modint<mod> &operator /=(int o){return *this *= ((modint<mod>(o))^=mod-2);}
	template<class I>friend modint<mod> operator +(modint<mod> a,I b){return a+=b;}
    template<class I>friend modint<mod> operator -(modint<mod> a,I b){return a-=b;}
    template<class I>friend modint<mod> operator *(modint<mod> a,I b){return a*=b;}
    template<class I>friend modint<mod> operator /(modint<mod> a,I b){return a/=b;}
    friend modint<mod> operator ^(modint<mod> a,int b){return a^=b;}
    friend bool operator ==(modint<mod> a,int b){return a.x==b;}
    friend bool operator !=(modint<mod> a,int b){return a.x!=b;}
    bool operator ! () {return !x;}
    modint<mod> operator - () {return x?mod-x:0;}
	modint<mod> &operator++(int){return *this+=1;}
};
typedef modint<1000000007> mint;
const int N=(1<<16)+100,M=503;
int n,m;
mint f[M][N],a[N],b[N];
void init(mint *A,mint *B){for(int i=0;i<n;i++)a[i]=A[i],b[i]=B[i];}
void mul(){for(int i=0;i<n;i++)a[i]*=b[i];}
void add(mint *A){for(int i=0;i<n;i++)A[i]+=a[i];}
void OR(mint *f,mint op=1){
	for(int o=2,k=1;o<=n;o<<=1,k<<=1)
		for(int i=0;i<n;i+=o)
			for(int j=0;j<k;j++)
				f[i+j+k]+=f[i+j]*op;
}
void AND(mint *f,mint op=1){
	for(int o=2,k=1;o<=n;o<<=1,k<<=1)
		for(int i=0;i<n;i+=o)
			for(int j=0;j<k;j++)
				f[i+j]+=f[i+j+k]*op;
}
int fa[M],h[16][5];
vector<int>e[M];
char s[M],c[M];
void dfs(int x){
	if(!e[x].size()){
		if(c[x]=='?'){
			for(int i=0;i<4;i++){
				int k=0;
				for(int j=0;j<m;j++)k|=h[j][i]<<j;
				f[x][k]+=1;f[x][((1<<m)-1)^k]+=1;
			}
		}else{
			int i,k=0;if('A'<=c[x]&&c[x]<='Z')i=c[x]-'A';else i=c[x]-'a';
			for(int j=0;j<m;j++)k|=h[j][i]<<j;
			if('A'<=c[x]&&c[x]<='Z')f[x][k]+=1;
			else f[x][((1<<m)-1)^k]+=1;
		}
		return;
	}
	int lc,rc;
	dfs(lc=e[x][0]);
	dfs(rc=e[x][1]);
	if(c[x]!='&')init(f[lc],f[rc]),OR(a),OR(b),mul(),OR(a,-1),add(f[x]);
	if(c[x]!='|')init(f[lc],f[rc]),AND(a),AND(b),mul(),AND(a,-1),add(f[x]);
}
signed main(){
	scanf("%s",s+1);int k=strlen(s+1);
	scanf("%d",&m);n=1<<m;
	int cnt=1,tot=1;
	for(int i=1;i<=k;i++){
		if(s[i]=='(')e[cnt].push_back(++tot),fa[tot]=cnt,cnt=tot;
		else if(s[i]==')')cnt=fa[cnt];
		else c[cnt]=s[i];
	}
	for(int i=0;i<m;i++)
		for(int j=0;j<5;j++)
			scanf("%d",&h[i][j]);
	dfs(1);
	int o=0;
	for(int i=0;i<m;i++)o|=h[i][4]<<i;
	printf("%d",f[1][o]);
	return 0;
}