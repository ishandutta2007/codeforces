#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef bitset<4096> bits;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=100005;
int b[N][15],p[15],n,m,k,Q;
bits a[N+15];

int main(){
	read(m),read(n),read(Q),k=n;
	rep(i,1,n){
		rep(j,1,m) read(b[j][i]);
		REP(s,1<<k) a[i][s]=s>>(i-1)&1;
	}
	rep(i,1,Q){
		int ty,x,y;
		read(ty),read(x),read(y);
		if(ty==1) a[++n]=a[x]&a[y];
		else if(ty==2) a[++n]=a[x]|a[y];
		else{
			rep(j,1,k) p[j]=j;
			sort(p+1,p+k+1,[&](int A,int B){
				return b[y][A]<b[y][B];
			});
			int aim=0,s=0;
			rep(j,1,k){
				s|=1<<(p[j]-1);
				if(a[x][s]) { aim=p[j]; break; }
			}
			printf("%d\n",b[y][aim]);
		}
	}
	return 0;
}