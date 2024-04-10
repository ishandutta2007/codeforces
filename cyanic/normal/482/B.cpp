#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef double ld;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=100005;
int s[N][30],t[N][30],l[N],r[N],v[N];
int n,m;

int main(){
	read(n),read(m);
	rep(i,1,m){
		read(l[i]),read(r[i]),read(v[i]);
		REP(k,30){
			if(!(v[i]>>k&1)) continue;
			s[l[i]][k]++,s[r[i]+1][k]--;
		}
	}
	rep(i,1,n){
		REP(k,30){
			s[i][k]+=s[i-1][k];
			t[i][k]=t[i-1][k]+(s[i][k]>0);
		}
	}
	rep(i,1,m){
		REP(k,30){
			int now=(t[r[i]][k]-t[l[i]-1][k]==(r[i]-l[i]+1));
			if(now!=(v[i]>>k&1)){
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	rep(i,1,n){
		int val=0;
		REP(k,30){
			if(s[i][k]>0) val|=1<<k;
		}
		printf("%d%c",val," \n"[i==n]);
	}
	return 0;
}