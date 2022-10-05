#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;

const int N=200005;
set<int> p[26][26],s,re;
int t[N],c[26],n,las;
vector<pii> ans;
char st[N];

int qry(int x){
	int res=0;
	for(;x;x-=(x&-x)) res+=t[x];
	return res;
}
void push(int l,int r){
	ans.pb(mp(qry(l-1)+1,qry(r)));
	auto it=re.lower_bound(l);
	for(;it!=re.end()&&*it<=r;re.erase(it++))
		for(int x=*it;x<=n;x+=(x&-x)) t[x]--;
}

void rmain(){
	scanf("%s",st+1);
	n=strlen(st+1),las=0;
	fill(c,c+26,0);
	rep(i,1,n) t[i]=(i&-i),re.insert(i),st[i]-='a';
	rep(i,1,n-1) if(st[i]==st[i+1]){
		if(las) p[st[las]][st[i]].insert(i);
		s.insert(las=i),c[st[i]]++;
	}
	ans.clear();
	for(;!s.empty();){
		int mx=0,t=0,k=*s.begin();
		REP(x,26) if(c[x]>mx) mx=c[x],t=x;
		REP(y,26) if(t!=y){
			if(p[t][y].size()) k=*p[t][y].begin();
			if(p[y][t].size()) k=*p[y][t].begin();
		}
		auto it=s.find(k);
		int x=(it!=s.begin()?*prev(it):0),y=*it;
		int l=(x&&prev(it)!=s.begin()?*prev(prev(it)):0);
		int r=(next(it)!=s.end()?*next(it):0);
		push(x+1,y),s.erase(x),s.erase(y);
		if(x&&y) p[st[x]][st[y]].erase(y);
		if(l&&x) p[st[l]][st[x]].erase(x);
		if(y&&r) p[st[y]][st[r]].erase(r);
		if(l&&r) p[st[l]][st[r]].insert(r);
		c[st[x]]--,c[st[y]]--;
	}
	push(1,n),printf("%d\n",(int)ans.size());
	for(auto x:ans) printf("%d %d\n",x.fi,x.se);
}

int main(){
	int T; cin>>T;
	while(T--) rmain();
	return 0;
}