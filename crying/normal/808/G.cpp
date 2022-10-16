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
const int MAXN=1e5+10,INF=1e9;
char s[MAXN],t[MAXN];
int n,m,ans;
int f[2][MAXN];
struct ACAM{
	int ch[MAXN][26],fail[MAXN],tot;
	queue<int>q;
	void insert(char* s){
		int u=0;
		for(int i=1;s[i];i++){
			if(!ch[u][s[i]-'a'])ch[u][s[i]-'a']=++tot;
			u=ch[u][s[i]-'a'];
		}
	}
	void build(){
		rep(j,0,25)if(ch[0][j])q.push(ch[0][j]);
		while(q.size()){
			int u=q.front();q.pop();
			rep(j,0,25){
				if(ch[u][j]){
					fail[ch[u][j]]=ch[fail[u]][j];
					q.push(ch[u][j]);
				}else ch[u][j]=ch[fail[u]][j];
			}
		}
	}
}acm; //tac 
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1);m=strlen(t+1);
	acm.insert(t);
	acm.build();
	rep(i,0,1)rep(j,0,m)f[i][j]=-INF;
	f[0][0]=0;
	rep(i,0,n-1){ 
		rep(j,0,m){
			if(s[i+1]!='?')f[(i+1)&1][acm.ch[j][s[i+1]-'a']]=Max(f[(i+1)&1][acm.ch[j][s[i+1]-'a']],f[i&1][j]+(acm.ch[j][s[i+1]-'a']==m));
			else rep(x,0,25){
				f[(i+1)&1][acm.ch[j][x]]=Max(f[(i+1)&1][acm.ch[j][x]],f[i&1][j]+(acm.ch[j][x]==m)); 
			}
		}
		rep(j,0,m)f[i&1][j]=-INF; // 
	}
	rep(j,0,m)ans=Max(ans,f[n&1][j]);
	printf("%d",ans); 
	return 0;
}