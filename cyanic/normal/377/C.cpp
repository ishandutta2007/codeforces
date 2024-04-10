#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define clr(x) memset(x,0,sizeof x)
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=(1<<20)+5;
int f[N],v[105],op[N],t[N],n,m;
char ch[5];

int main(){
	read(n);
	REP(i,n) read(v[i]);
	sort(v,v+n,greater<int>());
	read(m);
	rep(i,1,m){
		scanf("%s",ch);
		op[i]=(ch[0]=='p');
		read(t[i]),t[i]--;
	}
	memset(f,0xc0,sizeof f);
	f[0]=0;
	for(int s=1;s<(1<<m);s++){
		int k=__builtin_popcount(s);
		k=m-k+1;
		REP(i,n){
			if(!(s>>i&1)) continue;
			int e=s^(1<<i),val=f[e];
			if(t[k]^t[k+1]) val=-val;
			f[s]=max(f[s],val+op[k]*v[i]);
		}
	}
	int ans=f[(1<<m)-1];
	if(t[1]) ans=-ans;
	printf("%d\n",ans);
	return 0;
}