#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 303000;
int n,m;vector<char>s[N];
void print(vector<char>s[N]){
	rep(i,1,n){rep(j,1,m)printf("%c",s[i][j]);puts("");}
}
char ch[]={'A','G','C','T'};
void solve1(vector<char>a[N],int &res){
	res=1e9;
	rep(x,0,3)rep(y,x+1,3){
		static vector<char>b[N];int now=0;
		rep(i,1,n)b[i].resize(m+1);
		char c[2][2];c[0][0]=ch[x];c[0][1]=ch[y];int l=0;
		if(0!=x&&0!=y)c[1][l++]=ch[0];
		if(1!=x&&1!=y)c[1][l++]=ch[1];
		if(2!=x&&2!=y)c[1][l++]=ch[2];
		if(3!=x&&3!=y)c[1][l++]=ch[3];
		rep(j,1,m){
			int v[2]={0};
			rep(k,0,1)rep(i,1,n)v[k]+=s[i][j]!=c[j&1][(i&1)^k];
			if(v[0]<v[1]){now+=v[0];rep(i,1,n)b[i][j]=c[j&1][i&1];}
			else{now+=v[1];rep(i,1,n)b[i][j]=c[j&1][(i&1)^1];}
		}
		if(now<res){res=now;rep(i,1,n)a[i]=b[i];}
	}
}
void solve2(vector<char>a[N],int &res){
	res=1e9;
	rep(x,0,3)rep(y,x+1,3){
		static vector<char>b[N];int now=0;
		rep(i,1,n)b[i].resize(m+1);
		char c[2][2];c[0][0]=ch[x];c[0][1]=ch[y];int l=0;
		if(0!=x&&0!=y)c[1][l++]=ch[0];
		if(1!=x&&1!=y)c[1][l++]=ch[1];
		if(2!=x&&2!=y)c[1][l++]=ch[2];
		if(3!=x&&3!=y)c[1][l++]=ch[3];
		rep(i,1,n){
			int v[2]={0};
			rep(k,0,1)rep(j,1,m)v[k]+=s[i][j]!=c[i&1][(j&1)^k];
			if(v[0]<v[1]){now+=v[0];rep(j,1,m)b[i][j]=c[i&1][j&1];}
			else{now+=v[1];rep(j,1,m)b[i][j]=c[i&1][(j&1)^1];}
		}
		if(now<res){res=now;rep(i,1,n)a[i]=b[i];}
	}
}
int main(){
	read(n);read(m);rep(i,1,n){
		s[i].pb(' ');char t[N];scanf("%s",t+1);
		rep(j,1,m)s[i].pb(t[j]);
	}
	static vector<char>a[N],b[N];int x,y;
	solve1(a,x);solve2(b,y);
	if(x<y)print(a);else print(b);
	return 0;
}