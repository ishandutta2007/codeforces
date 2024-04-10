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

const int N=200005;
map<pii,int> same;
vector<pii> q;
int x[N],y[N];
vi ans[3];
int n,m;

char st[N];
void qry(){
	if(!q.size())return;
	printf("Q %d ",(int)q.size());
	REP(i,q.size())printf(" %d %d ",q[i].fi,q[i].se);
	puts(""),fflush(stdout);
	scanf("%s",st);
	REP(i,q.size())same[q[i]]=st[i]-'0';
}

void MAIN(){
	same.clear();
	scanf("%d",&n);
	q.clear();
	for(int i=1;i+1<=n;i+=2)
		q.pb(mp(i,i+1));
	qry();
	q.clear();
	for(int i=2;i+1<=n;i+=2)
		q.pb(mp(i,i+1));
	qry();
	m=0;
	rep(i,1,n)
		if(!same[mp(i-1,i)])x[++m]=i;
	q.clear();
	for(int i=1;i+2<=m;i+=4)
		q.pb(mp(x[i],x[i+2]));
	for(int i=2;i+2<=m;i+=4)
		q.pb(mp(x[i],x[i+2]));
	qry();
	q.clear();
	for(int i=3;i+2<=m;i+=4)
		q.pb(mp(x[i],x[i+2]));
	for(int i=4;i+2<=m;i+=4)
		q.pb(mp(x[i],x[i+2]));
	qry();
	memset(y,-1,sizeof y);
	y[x[1]]=0,(m>=2?y[x[2]]=1:0);
	for(int i=3;i<=m;i++)
		if(same[mp(x[i-2],x[i])])y[x[i]]=y[x[i-2]];
		else y[x[i]]=3-y[x[i-2]]-y[x[i-1]];
	rep(i,1,n){
		if(y[i]==-1)y[i]=y[i-1];
		ans[y[i]].pb(i);
	}
	printf("A %d %d %d\n",(int)ans[0].size(),
				(int)ans[1].size(),(int)ans[2].size());
	REP(t,3){
		for(auto x:ans[t])printf("%d ",x);
		puts(""),ans[t].clear();
	}
	fflush(stdout);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--)MAIN();
	return 0;
}