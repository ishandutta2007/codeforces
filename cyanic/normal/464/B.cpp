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

#define XY swap(x[k],y[k]);
#define YZ swap(y[k],z[k]);
#define ZX swap(z[k],x[k]);

int p[9][3],q[9][3],o[3],r[3];

ll len(int i,int j){
	ll res=0;
	REP(t,3)
		res+=(ll)(q[i][t]-q[j][t])*(q[i][t]-q[j][t]);
	return res;
}

void check(){
	map<ll,int> cnt;
	rep(i,0,7)rep(j,i+1,7)
		cnt[len(i,j)]++;
	ll mn=cnt.begin()->fi;
	if(cnt[mn]!=12)return;
	if(cnt[mn*2]!=12)return;
	if(cnt[mn*3]!=4)return;
	puts("YES");
	REP(i,8){
		REP(t,3)printf("%d ",q[i][t]);
		puts("");
	}
	exit(0);
}

void dfs(int k){
	if(k==8){
		check();
		return;
	}
	int r[3];
	REP(t,3)r[t]=t+1;
	do{
		REP(t,3)q[k][r[t]-1]=p[k][t];
		dfs(k+1);
	}while(next_permutation(r,r+3));
}

int main(){
	REP(i,8)REP(k,3)
		read(p[i][k]);
	REP(t,3)q[0][t]=p[0][t];
	dfs(1);
	puts("NO");
	return 0;
}