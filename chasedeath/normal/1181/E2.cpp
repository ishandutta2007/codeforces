#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

#define rep(a,b,c) for(int a=b,a##end=c;a<=a##end;++a)
#define drep(a,b,c) for(int a=b,a##end=c;a>=a##end;--a)

char IO;
int rd(){
	int s=0,f=0;
	while(IO=getchar(),IO<'0'||IO>'9')if(IO=='-')f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(IO=getchar(),IO>='0'&&IO<='9');
	return f?-s:s;
}

/*-----------------------------------------------------------------------
  A little wish for the a AC !
  (^_^)
  Instructed by Candy_Bar
  -------------------------------------------------------------------------*/


const int N=1e5+10;

int n;

struct Rec{
	int a,b,c,d;
	void Get(){ a=rd(),b=rd(),c=rd(),d=rd(); }
}A[N];

struct node{
	int a,b,id;
	void Get(Rec x,int k,int i){
		if(k==0) a=x.a,b=x.c;
		else if(k==1) a=-x.c,b=-x.a;
		else if(k==2) a=x.b,b=x.d;
		else if(k==3) a=-x.d,b=-x.b;
		id=i;
	}
	bool operator < (const node __) const {
		if(a^__.a) return a<__.a;
		return id<__.id;
	}
};

node s[N][4];

const int INF=1e9;

typedef set<node> ::iterator iter;
bool dfs(set <node> st[4]){
	if(st[0].size()<=1) return true;
	iter it[4],t; rep(i,0,3) it[i]=st[i].begin();
	set <node> S[4]; rep(i,0,3) S[i].clear();
	int ma[4]={-INF,-INF,-INF,-INF};
	rep(o,1,st[0].size()-1){
		rep(i,0,3) {
			ma[i]=max(ma[i],it[i]->b);
			it[i]++;
			if(it[i]->a>=ma[i]) {
				for(t=st[i].begin();t!=it[i];){
					int id=t->id;t++;
					rep(j,0,3) {
						S[j].insert(s[id][j]);
						st[j].erase(s[id][j]);
					}
				}
				return dfs(st)&&dfs(S);
			}
		}
	}
	return false;
}


set <node> st[4];

int main(){
	n=rd();
	rep(i,1,n) A[i].Get();
	rep(i,1,n) rep(j,0,3) {
		s[i][j].Get(A[i],j,i);
		st[j].insert(s[i][j]);
	}
	int ans=dfs(st);
	puts(ans?"YES":"NO");
}