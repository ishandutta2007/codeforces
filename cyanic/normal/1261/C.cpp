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

const int N=1000005;
vi s[N],t[N],f[N],g[N];
int n,m;

int getS(vi s[N],int x,int y,int d){
	int U=max(1,x-d),D=min(n,x+d);
	int L=max(1,y-d),R=min(m,y+d);
	return s[D][R]-s[U-1][R]-s[D][L-1]+s[U-1][L-1];
}

int chk(int d){
	rep(i,1,n){
		rep(j,1,m){
			if(getS(s,i,j,d)==(2*d+1)*(2*d+1)){
				f[i][j]=1;
			}
			else{
				f[i][j]=0;
			}
		}
	}
	rep(i,1,n){
		rep(j,1,m){
			g[i][j]=g[i-1][j]+g[i][j-1]-g[i-1][j-1]+f[i][j];
		}
	}
	rep(i,1,n){
		rep(j,1,m){
			if(t[i][j]&&getS(g,i,j,d)==0){
				return 0;
			}
		}
	}
	return 1;
}

int main(){
	read(n),read(m);
	rep(i,0,n+1){
		s[i].resize(m+2);
		t[i].resize(m+2);
		f[i].resize(m+2);
		g[i].resize(m+2);
	}
	static char st[N];
	rep(i,1,n){
		scanf("%s",st+1);
		rep(j,1,m){
			s[i][j]=(st[j]=='X');
			t[i][j]=s[i][j];
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	}
	int l=0,r=min(n,m),mid;
	while(l<r){
		mid=(l+r+1)>>1;
		if(chk(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	chk(l);
	printf("%d\n",l);
	rep(i,1,n){
		rep(j,1,m){
			putchar(f[i][j]?'X':'.');
		}
		puts("");
	}

	return 0;
}