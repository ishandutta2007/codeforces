#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define bits bitset<N>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N=1005;
int d[N],fa[N],n,K,mx;
vi x[N];

char s[N];
bits qry(bits r,int dis){
	if(!dis||r.none())return r;
	dis=min(dis,mx);
	putchar('?');
	rep(i,1,n)printf(" %d",(int)r[i]*dis);
	puts("");
	fflush(stdout);
	scanf("%s",s+1);
	bits res;
	rep(i,1,n)res[i]=r[i]|(s[i]-'0');
	return res;
}

void solve(int k,vector<bits> s,bits r0){
	bits r1;
	for(;;){
		if(!k){
			REP(p,s.size())
				for(int i=s[p]._Find_first();i<=n;i=s[p]._Find_next(i))
					d[i]=p,cerr<<i<<"   "<<p<<endl;
			return;
		}
		int t=1<<(k-1);
		bits ret0=qry(r0,t-1),ret1=qry(r0,t);
		bits ret2=qry(r1,t-1),ret3=qry(r1,t);
		vector<bits> ss;
		bits A,B,delta;
		r0|=r1,r1.reset();
		REP(i,s.size())if(!(i&1)){
			A=ret0&s[i],B=ret1&s[i];
			delta=A^B,r1|=delta;
			ss.pb(A),ss.pb(s[i]^A);
		}
		else{
			A=ret2&s[i],B=ret3&s[i];
			delta=A^B,r1|=delta;
			ss.pb(A),ss.pb(s[i]^A);
		}
		k--,s=ss;
	}
}

void part1(){
	bits rts;
	vector<bits>full;
	full.resize(1);
	rep(i,1,n)full[0].set(i);
	rts.set(1);
	solve(K,full,rts);
}

int state[N];

void doit(int w){
	REP(p,K){
		bits QwQ;
		for(int i=w;i<=mx;i+=3)
			REP(j,x[i].size())
				if(j>>p&1)QwQ.set(x[i][j]);
		bits OwO=qry(QwQ,1);
		for(int i=(w+1)%3;i<=mx;i+=3)
			REP(j,x[i].size())
				if(OwO.test(x[i][j]))state[x[i][j]]|=1<<p;
	}
	for(int i=(w+1)%3;i<=mx;i+=3)
		REP(j,x[i].size())if(i)
			fa[x[i][j]]=x[i-1][state[x[i][j]]];
}

void part2(){
	rep(i,1,n)x[d[i]].pb(i);
	REP(t,3)doit(t);
}

int main(){
	scanf("%d",&n),mx=n-1;
	K=1;while((1<<K)<=mx)K++;
	part1();
	part2();
	puts("!");
	rep(i,2,n)printf("%d %d\n",i,fa[i]);
	fflush(stdout);
	return 0;
}