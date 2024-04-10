#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=4010,INF=1e9;
int a,b,c,d,n,m,f[MAXN][MAXN];
pi g[MAXN][MAXN];
int bucket1[26],bucket2[26];
char s[MAXN],t[MAXN];
void calc(int i,int j){
	if(s[i]==t[j])f[i][j]=Min(f[i][j],f[i-1][j-1]);
	//1.
	f[i][j]=Min(f[i][j],a+f[i][j-1]); 
	//2.
	f[i][j]=Min(f[i][j],b+f[i-1][j]);
	//3.
	f[i][j]=Min(f[i][j],c+f[i-1][j-1]);
	//4.
	pi zero=mp(0,0);
	if(g[i][j]!=zero){
		int x=g[i][j].fr,y=g[i][j].se;
		//sxsi
		//sxtj,sity
		int cost=d+(i-x-1)*b+(j-y-1)*a; 
		f[i][j]=Min(f[i][j],f[x-1][y-1]+cost); 
	} 
}
int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);
	m=strlen(t+1);
	rep(i,0,n)rep(j,0,m)f[i][j]=INF,g[i][j]=mp(0,0);
	f[0][0]=0;
	rep(i,1,n)f[i][0]=i*b;
	rep(i,1,m)f[0][i]=i*a;
	rep(i,1,n){
		memset(bucket2,0,sizeof bucket2);
		rep(j,1,m){
			if(bucket1[t[j]-'a'] && bucket2[s[i]-'a']){
				g[i][j]=mp(bucket1[t[j]-'a'],bucket2[s[i]-'a']);
			}
			bucket2[t[j]-'a']=j;
		}
		bucket1[s[i]-'a']=i;
	}
	rep(i,1,n){
		rep(j,1,m){
			calc(i,j);
		}
	}
	printf("%d",f[n][m]);
	return 0;
}