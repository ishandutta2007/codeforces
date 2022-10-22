#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=1e6+100;
template<const int mod>
struct modint{
    int x;
    modint<mod>(int o=0){x=o;}
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
using mint=modint<998244353>;
//map 0 -1  1
struct KK{
	/*
	 
	00  11
	11  00
	
	10  01
	10  01
	
	*/
	void init(int N,int M){
		n=N,m=M,two=M-2;
	}
	int n,m;
	int ban[N][2];///
	int two;//
	int zero;//
	map<pair<int,int>,int>M;//
	void dec(int y){
		if(y<=2)return;
		if(!ban[y][0]&&!ban[y][1])two--;
		if(ban[y][0]&&ban[y][1])zero--;
	}
	void add(int y){
		if(y<=2)return;
		if(!ban[y][0]&&!ban[y][1])two++;
		if(ban[y][0]&&ban[y][1])zero++;
	}
	void upd(int x,int y,int op){
		dec(y);
		if(M[mp(x,y)]==-1)ban[y][x&1]--;
		if(M[mp(x,y)]==1)ban[y][x&1^1]--;
		M[mp(x,y)]=op;
		if(M[mp(x,y)]==-1)ban[y][x&1]++;
		if(M[mp(x,y)]==1)ban[y][x&1^1]++;
		add(y);
	}
	mint qry(){
		mint res=0;
		if(zero)return res;
		if(!ban[1][0]&&!ban[2][0])res+=mint(2)^two;
		if(!ban[1][1]&&!ban[2][1])res+=mint(2)^two;
		return res;
	}
}A,B;//AB
struct CFNM{
	/*
	
	01   10
	10   01
	
	
	
	*/
	void init(int N,int M){
		n=N,m=M,two=N-2;
	}
	int n,m;
	int two;//
	int zero;//
	int ban[N][2];//ban/
	int wzp[2];//ban
	map<pair<int,int>,int>M;
	void dec(int x){
		if(ban[x][0])wzp[x&1]--;
		if(ban[x][1])wzp[x&1^1]--;
		if(x<=2)return;
		if(!ban[x][0]&&!ban[x][1])two--;
		if(ban[x][0]&&ban[x][1])zero--;
	}
	void add(int x){
		if(ban[x][0])wzp[x&1]++;
		if(ban[x][1])wzp[x&1^1]++;
		if(x<=2)return;
		if(!ban[x][0]&&!ban[x][1])two++;
		if(ban[x][0]&&ban[x][1])zero++;
	}
	void upd(int x,int y,int op){
		dec(x);
		if(M[mp(x,y)]==-1)ban[x][y&1]--;
		if(M[mp(x,y)]==1)ban[x][y&1^1]--;
		M[mp(x,y)]=op;
		if(M[mp(x,y)]==-1)ban[x][y&1]++;
		if(M[mp(x,y)]==1)ban[x][y&1^1]++;
		add(x);
	}
	mint qry(){
		mint res=0;
		if(!zero){
			if(!ban[1][0]&&!ban[2][1])res+=mint(2)^two;
			if(!ban[1][1]&&!ban[2][0])res+=mint(2)^two;
			if(!wzp[0])res=res-1;
			if(!wzp[1])res=res-1;
		}
		if(!A.ban[1][0]&&!A.ban[2][1]&&!A.zero)res+=mint(2)^A.two;
		if(!A.ban[1][1]&&!A.ban[2][0]&&!A.zero)res+=mint(2)^A.two;
		return res;
	}
}C;
int n,m,k;
signed main(){
	read(n,m,k);
	A.init(n,m);B.init(m,n);C.init(n,m);
	while(k--){
		int x,y,op;read(x,y,op);
		if(op==0)op=-1;else if(op==-1)op=0;
		A.upd(x,y,op);
		B.upd(y,x,op);
		C.upd(x,y,op);
		//printf("%d %d %d\n",A.qry(),B.qry(),C.qry());
		write((A.qry()+B.qry()+C.qry()).x);
		putchar('\n');
	}
}