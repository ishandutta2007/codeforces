#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
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

const int N=100005;
int n,flag,res,m[2],c[2][2],cnt[2];
set<int> s[2][2];
vi vec[2][N],ans;
char st[N];

void push(vi &vec){
	for(auto x:vec)ans.pb(x);
}
#define f(x,y) !s[x][y].empty()
#define doit(x,y) push(vec[x][*s[x][y].begin()]),\
				  s[x][y].erase(s[x][y].begin())

void Case1(){
	while(f(0,1))doit(0,1);
	while(f(0,0)||f(1,1)){
		if(f(0,0))doit(0,0);
		if(f(1,1))doit(1,1);
	}
	while(f(1,0))doit(1,0);
}

void Case2(){
	if(f(1,0)&&f(0,1)&&!f(0,0)&&!f(1,1)){
		int flag=0,X=0,Y=0;
		for(auto x:s[0][1])
			if(vec[0][x].back()==n){
				vec[1][*s[1][0].begin()].pb(n);
				vec[0][x].pop_back();
				X=x,Y=*s[1][0].begin();
				flag=1; break;
			}
		if(flag){
			s[1][0].erase(Y);
			s[1][1].insert(Y);
			s[0][1].erase(X);
			s[0][0].insert(X);
		}
		else{			
			for(auto x:s[1][0])
				if(vec[1][x].back()==n){
					vec[0][*s[0][1].begin()].pb(n);
					vec[1][x].pop_back();
					X=x,Y=*s[0][1].begin();
					flag=1; break;
				}
			if(flag){
				s[0][1].erase(Y);
				s[0][0].insert(Y);
				s[1][0].erase(X);
				s[1][1].insert(X);
			}
			assert(flag);
		}
	}
	if(f(0,0))doit(0,0);
	while(f(1,0))doit(1,0);
	if(f(1,1))doit(1,1);
	while(f(0,1))doit(0,1);
	while(f(0,0)){
		doit(0,0);
		doit(1,1);
	}
}

int main(){
	scanf("%s",st+1);
	n=strlen(st+1);
	rep(i,1,n)cnt[st[i]=='R']++;
	if(cnt[1]>cnt[0])flag=1;
	rep(i,1,n){
		int x=(st[i]=='L'?0:1)^flag;
		if(!s[0][x^1].empty()){
			int y=*s[0][x^1].begin();
			s[0][x^1].erase(y);
			vec[0][y].pb(i);
			s[0][x].insert(y);
		}
		else if(!s[1][x^1].empty()){
			int y=*s[1][x^1].begin();
			s[1][x^1].erase(y);
			vec[1][y].pb(i);
			s[1][x].insert(y);
		}
		else{
			++res;
			vec[x][++m[x]].pb(i);
			s[x][x].insert(m[x]);
		}
	}
	REP(a,2)REP(b,2)
		c[a][b]=s[a][b].size();
	if(cnt[0]^cnt[1]) Case1();
	else Case2();
	printf("%d\n",res-1);
	for(auto x:ans)printf("%d ",x);
	puts("");
	return 0;
}