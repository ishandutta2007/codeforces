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
typedef long double ld;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=10005;
ld f[2][N],s[2][N],p[N],x;
int n,cur,nxt;
 
int main(){
	read(n),read(x);
	x/=1000000;
	rep(i,0,n){
		read(p[i]);
		p[i]/=1000000;
	}
	rep(i,0,n){
		s[cur][i]=p[i];
		rep(j,1,i) s[cur][i]=s[cur][i]/(n+1-j)*j;
	}
	nxt=1;
	per(i,n-1,0){
		rep(j,0,i){
			s[nxt][j]=s[cur][j]+s[cur][j+1];
			if(s[nxt][j]){
				ld A=s[cur][j+1]/s[nxt][j],B=1-A;
				ld now=A*(f[cur][j+1]+1)+B*f[cur][j]-x;
				f[nxt][j]=max(ld(0),now);
			}
			else f[nxt][j]=0;
		}
		swap(nxt,cur);
	}
	printf("%.10lf\n",double(f[cur][0]));
	return 0;
}