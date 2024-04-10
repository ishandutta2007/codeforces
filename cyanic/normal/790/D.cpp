#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
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

const int N=300005;
unordered_map<int,int> f[N];
int a[3][N],p[3][N],n;

int solve(int x,int y){
	if(f[x].count(y)) return f[x][y];
	if(p[0][x]==-1&&p[1][y]==-1&&p[2][min(x,y)]==-1) return 0;
	int res=(p[0][x]>p[1][y]?solve(p[0][x],y):(p[1][y]>=0?solve(x,p[1][y]):0));
	int tmp=p[2][min(x,y)]; if(tmp>=0) res=max(res,solve(tmp,tmp));
	return f[x][y]=res+1;
}

int main(){
	read(n);
	REP(i,2) rep(j,1,n) read(a[i][j]);
	rep(j,1,n) a[2][j]=a[0][j]+a[1][j];
	REP(t,3){
		unordered_map<ll,int> pos;
		ll s=0; pos[s]=0,p[t][0]=-1;
		rep(i,1,n){
			s+=a[t][i];
			p[t][i]=pos.count(s)?pos[s]:-1;
			p[t][i]=max(p[t][i],p[t][i-1]);
			pos[s]=i;
		}
	}
	cout<<solve(n,n)<<endl;
	return 0;
}