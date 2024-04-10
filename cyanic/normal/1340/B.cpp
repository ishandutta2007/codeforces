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

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const char num[10][8]={
	 "1110111", "0010010", "1011101", "1011011", "0111010",
	 "1101011", "1101111", "1010010", "1111111", "1111011"
};
const int N=2005;
int c[N][10],n,K;
bitset<N> f[N];
char s[8];

int doit(char s[8],const char t[8]){
	int res=0;
	REP(i,8){
		if(s[i]==t[i]) continue;
		if(s[i]=='1'&&t[i]=='0') return -1;
		res++;
	}
	return res;
}

void solve(int i,int k){
	per(j,9,0){
		if(c[i][j]==-1||c[i][j]>k) continue;
		if(f[i+1][k-c[i][j]]){
			putchar('0'+j);
			solve(i+1,k-c[i][j]);
			return;
		}
	}
}

int main(){
	read(n),read(K);
	rep(i,1,n){
		scanf("%s",s);
		REP(j,10) c[i][j]=doit(s,num[j]);
	}
	f[n+1][0]=1;
	per(i,n,1) REP(j,10){
		if(c[i][j]>=0) f[i]|=f[i+1]<<c[i][j];
	}
	if(!f[1][K]){
		puts("-1");
		return 0;
	}
	solve(1,K);
	return 0;
}