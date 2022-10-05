#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=505,S=(1<<16)+5,mod=1e9+7,ALL=(1<<16)-1;
int f[N][S],lc[N],rc[N],op[N];
int n,rt,sz,s0,s1,Q,a,b,c,d,e;
char s[N];

namespace{
	void add(int &x,int y){
		x=(x+y>=mod?x+y-mod:x+y);
	}
	void sub(int &x,int y){
		x=(x-y<0?x-y+mod:x-y);
	}
	int power(int x,int p){
		int res=1;
		for(;p;p>>=1,x=(ll)x*x%mod)
			if(p&1)res=(ll)res*x%mod;
		return res;
	}
	void AND(int a[],int op){
		for(int k=0,d=1;k<16;k++,d<<=1)
			for(int i=0;i<(1<<16);i+=d<<1){
				int *l=a+i,*r=a+i+d;
				if(!op)REP(j,d)add(*l++,*r++);
				else REP(j,d)sub(*l++,*r++);
			}
	}
	void OR(int a[],int op){
		for(int k=0,d=1;k<16;k++,d<<=1)
			for(int i=0;i<(1<<16);i+=d<<1){
				int *l=a+i,*r=a+i+d;
				if(!op)REP(j,d)add(*r++,*l++);
				else REP(j,d)sub(*r++,*l++);
			}
	}
	void calcAND(int A[],int B[],int C[]){
		static int a[S],b[S],c[S];
		memcpy(a,A,sizeof a);
		memcpy(b,B,sizeof b);
		AND(a,0),AND(b,0);
		REP(s,1<<16)c[s]=(ll)a[s]*b[s]%mod;
		AND(c,1);
		REP(s,1<<16)add(C[s],c[s]);
	}
	void calcOR(int A[],int B[],int C[]){
		static int a[S],b[S],c[S];
		memcpy(a,A,sizeof a);
		memcpy(b,B,sizeof b);
		OR(a,0),OR(b,0);
		REP(s,1<<16)c[s]=(ll)a[s]*b[s]%mod;
		OR(c,1);
		REP(s,1<<16)add(C[s],c[s]);
	}
}

int build(int l,int r){
	if(l==r){
		int o=++sz;
		if('a'<=s[l]&&s[l]<='d')op[o]=-(s[l]-'a'+1);
		else if('A'<=s[l]&&s[l]<='D')op[o]=s[l]-'A'+1;
		return o;
	}
	int o=++sz,top=0,p=0;
	rep(i,l,r)
		if(s[i]=='(')top++;
		else if(s[i]==')')top--;
		else if(!top)p=i;
	if(s[p]=='&')op[o]=1;
	if(s[p]=='|')op[o]=2;
	lc[o]=build(l+1,p-2);
	rc[o]=build(p+2,r-1);
	return o;
}

void solve(int u){
	if(!lc[u]&&!rc[u]){
		REP(t,4)REP(v,2)
			if(!op[u]||t==abs(op[u])-1&&v==(op[u]<0))
				REP(s,1<<16)if(!(s&(ALL^s1^s0))){
					int flag=1;
					REP(k,16)
						if(((s0>>k&1)||(s1>>k&1))&&((k>>t&1)^v^(s>>k&1))){
							flag=0;
							break;
						}
					add(f[u][s],flag);
				}
		return;
	}
	solve(lc[u]),solve(rc[u]);
	if(op[u]!=2) calcAND(f[lc[u]],f[rc[u]],f[u]);
	if(op[u]!=1) calcOR(f[lc[u]],f[rc[u]],f[u]);
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	read(Q);
	rep(i,1,Q){
		read(a),a<<=0,read(b),b<<=1;
		read(c),c<<=2,read(d),d<<=3;
		read(e);
		if(e)s1|=1<<(a|b|c|d);
		else s0|=1<<(a|b|c|d);
	}
	rt=build(1,n);
	solve(rt);
	int ans=0;
	REP(s,1<<16)
		if((s&s1)==s1&&(~s&s0)==s0)
			add(ans,f[rt][s]);
	printf("%d\n",ans);
	return 0;
}