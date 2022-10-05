#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ctz __builtin_ctz
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

const int N=500005,mod=1e9+7;
const int M=10000005,lim=1e7;
int id[M],c[M],a[N],pw[N],val[256],ct[256];
int n,cnt,tot,ans,k;
vi pr[N];

int fix(int x){
	return x>=mod?x-mod:x;
}

bool flag[M];
void sieve(){
	for(int i=2;i<=lim;i++)
		if(!flag[i])
			for(int j=i;j<=lim;j+=i){
				flag[j]=1;
				if(id[j])pr[id[j]].pb(i);
			}
}

void calc(int x){
	vi &p=pr[id[x]];
	k=p.size(); val[0]=1;
	for(int s=1;s<(1<<k);s++){
		int d=ctz(s);
		val[s]=val[s^(1<<d)]*p[d];
	}
}

int main(){
	read(n),pw[0]=1;
	rep(i,1,n){
		read(a[i]);
		if(!id[a[i]])id[a[i]]=++cnt;
		pw[i]=fix(pw[i-1]+pw[i-1]);
	}
	rep(i,0,n)pw[i]--;
	for(int s=1;s<256;s++)
		ct[s]=ct[s^(1<<ctz(s))]+1;
	sieve();
	rep(i,1,n){
		calc(a[i]);
		for(int s=0;s<(1<<k);s++)
			c[val[s]]++;
		tot++;
		for(int s=1;s<(1<<k);s++)
			if(ct[s]&1)tot=fix(tot+pw[c[val[s]]-1]);
			else tot=fix(tot+mod-pw[c[val[s]]-1]);
	}
//	printf("tot = %d\n",tot);
	rep(i,1,n){
		calc(a[i]);
		int res=tot;
		for(int s=1;s<(1<<k);s++)
			if(ct[s]&1)res=fix(res+mod-pw[c[val[s]]]);
			else res=fix(res+pw[c[val[s]]]);
//		printf("res[%d] = %d\n",i,res);
		ans=fix(ans+res);
	}
	printf("%d\n",(ans+mod)%mod);
	return 0;
}