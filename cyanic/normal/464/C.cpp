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

const int N=100005,mod=1e9+7,phi=mod-1;
int x[N],a[N],val[N],len[N],n,Q,m;
char s[N];
vi b[N];

inline int power(int x,int p){
	int res=1;
	for(;p;p>>=1,x=(ll)x*x%mod)
		if(p&1)res=(ll)res*x%mod;
	return res;
}

void doit(int k){
	int Val=0,Len=0;
	for(auto x:b[k]){
		Val=(Val+(ll)power(10,Len)*val[x])%mod;
		Len=(Len+len[x])%phi;
	}
	val[a[k]]=Val,len[a[k]]=Len;
}

int main(){
	scanf("%s",s);
	m=strlen(s);
	per(k,m-1,0)
		b[0].pb(s[k]-'0');
	read(Q);
	rep(i,1,Q){
		scanf("%d->",&a[i],s);
		gets(s);
		m=strlen(s);
		per(k,m-1,0)
			b[i].pb(s[k]-'0');
	}
	REP(i,10)val[i]=i,len[i]=1;
	per(i,Q,0)
		doit(i);
	printf("%d\n",val[0]);
	return 0;
}