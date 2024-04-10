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

const int N=3005;
int pa[N*N],id[N][N],n,m,cnt,L,R,c1,c2;
char s[N][N];

void GG(){
	puts("-1"),exit(0);
}

int gp(int x){
	return pa[x]==x?x:pa[x]=gp(pa[x]);
}

int main(){
	read(n),read(m);
	rep(i,1,n){
		scanf("%s",s[i]+1);
		L=1;
		while(L<=m&&s[i][L]!='#') L++;
		R=m;
		while(R>=1&&s[i][R]!='#') R--;
		if(L>R) c1++;
		rep(j,L,R) if(s[i][j]=='.') GG();
	}
	rep(i,1,m){
		L=1;
		while(L<=n&&s[L][i]!='#') L++;
		R=n;
		while(R>=1&&s[R][i]!='#') R--;
		if(L>R) c2++;
		rep(j,L,R) if(s[j][i]=='.') GG();
	}
	if(c1&&!c2||c2&&!c1) GG();
	rep(i,1,n) rep(j,1,m){
		if(s[i][j]=='#') id[i][j]=++cnt;
	}
	rep(i,1,cnt) pa[i]=i;
	rep(i,1,n) rep(j,1,m){
		if(id[i][j]&&id[i+1][j]) pa[gp(id[i][j])]=gp(id[i+1][j]);
		if(id[i][j]&&id[i][j+1]) pa[gp(id[i][j])]=gp(id[i][j+1]);
	}
	int ans=0;
	rep(i,1,cnt) ans+=pa[i]==i;
	cout<<ans<<endl;
	return 0;
}