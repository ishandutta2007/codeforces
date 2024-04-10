#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef set<int> si;
#define mp make_pair
#define pb push_back
#define f first
#define s second
int INF = 1e9;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 100100
#define MAXL 18

int dst[MAXN];
vpi V[MAXN];
int p[MAXN][20], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN], D[MAXN][20];
int cur,N;

struct node{
	int s,e,m,v;
	node *l,*r;
	node(int _s, int _e): s(_s), e(_e){
		m=(s+e)/2;
		v=INF;
		if (s != e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	void up(int x, int y, int val){
		// if (s == 0 && e == MAXN){
		// 	cerr<<"update "<<x<<' '<<y<<'\n';
		// }
		if (s == x && y == e){
			v=min(v,val);
			return;
		}
		if (y <= m)l->up(x,y,val);
		else if(x>m)r->up(x,y,val);
		else {
			l->up(x,m,val);
			r->up(m+1,y,val);
		}
	}
	int query(int x){
		if (s ==e)return v;
		if (x <= m)return min(v,l->query(x));
		else return min(v,r->query(x));
	}
}*root;

int dfs(int x){
  int size = 1;
  int mchild = 0;
  for (auto i : V[x]){
    if (p[i.f][0]!=-1)continue;
    p[i.f][0] = x;
    D[i.f][0] = i.s;
    depth[i.f] = depth[x] + 1;
    dst[i.f] = dst[x] + i.s;
    int cs = dfs(i.f);
    size += cs;
    if (cs > mchild){
      mchild = cs;
      heavy[x] = i.f;
    }
  }
  return size;
}

void decompose(int x, int h){
  head[x] = h; pos[x] = cur++;
  if (heavy[x] != -1)decompose(heavy[x], h);
  for (auto i : V[x]){
    if (i.f == p[x][0])continue;
    if (i.f == heavy[x])continue;
    decompose(i.f,i.f);
  }
}

int LCA(int a, int b){
	if (a == b)return a;
	if (depth[a] < depth[b])swap(a,b);
	int h = depth[a]-depth[b];
	for (int i = 0; i < MAXL; i++) {
	  if (((1 << i) & h) > 0) { 
		a = p[a][i];
	  }
	}
	if (a == b)return a;
	for (int i = MAXL-1; i >= 0; i--){
		if (p[a][i] != p[b][i]){
			a = p[a][i];
			b = p[b][i];
		}
	}
	return p[a][0];
}

int fd(int c, int d){ // Distance from c to its d-th parent
  int ans = 0;
  for (int i = 0; i < MAXL; i++) {
    if (((1 << i) & d) > 0) {
      if (c==-1) return -1;
      ans = max(ans,D[c][i]);
      c = p[c][i];
    }
  }
  return ans;
}

int up[MAXN];
int par(int x){return (x==up[x])?x:up[x]=par(up[x]);}
struct edge{
    int a,b,w,ind,flag;
    edge(int c, int d, int e, int g):a(c),b(d),w(e),ind(g){flag=0;}
};

vector<edge> edgeList;
int E,a,b,w,ans;
bool cmp (edge a, edge b){
    return a.w<b.w;
}
vector<edge>trash;

void rangeup(int a, int b, int w){
    if (depth[a] > depth[b])swap(a,b);
    for (;head[a] != head[b]; b = p[head[b]][0]){
        if (depth[head[a]] > depth[head[b]])swap(a,b);
        root->up(pos[head[b]], pos[b], w);
    }
    if (a==b)return;
    if (depth[a] > depth[b])swap(a,b);
    // cerr<<pos[a]+1<<' '<<pos[b]<<'\n';
    root->up(pos[a]+1, pos[b], w);
}
int out[1000100];

int main(){
    // freopen("in.txt","r",stdin);
    cin>>N>>E;
    for (int i=1;i<=N;++i)up[i]=i;
    for (int i=0;i<E;++i){
        cin>>a>>b>>w;
        edgeList.pb({a,b,w,i});
    }
    sort(ALL(edgeList),cmp);
    for (int x=0;x<E;++x){
    	edge i = edgeList[x];
        int a=i.a;
        int b=i.b;
        if (par(a)==par(b)){
        	trash.pb(i);
        	continue;
        }
        up[par(a)]=par(b);
        V[a].pb(mp(b,i.w));
        V[b].pb(mp(a,i.w));
        edgeList[x].flag=1;
    }

    memset(p,-1,sizeof(p));
    memset(heavy,-1,sizeof(heavy));
    p[1][0]=0;
	cur = 1;
	dfs(1);
	decompose(1,1);
	// for (int i=1;i<=N;++i)cout<<pos[i]<<' ';cout<<'\n';

	for (int i = 1; i < MAXL; ++i){
      for (int j = 2; j <= N; ++j){
        if (p[j][i-1] != -1){
			p[j][i]=p[p[j][i-1]][i-1];
			D[j][i] = max(D[p[j][i-1]][i-1], D[j][i-1]);
		}
     }
    }

    // for (int i=1;i<=N;++i)cout<<D[i][0]<<' ';cout<<'\n';
	root=new node(0,MAXN);
	for (auto v : trash){
		rangeup(v.a,v.b,v.w);
	}
	for (int i=0;i<E;++i){
		edge x = edgeList[i];
		if (x.a == p[x.b][0])swap(x.a,x.b);
		if (x.flag==0){
			int l = LCA(x.a,x.b);
			// cout<<x.a<<' '<<x.b<<' '<<l<<'\n';
	  		int t = max(fd(x.a,depth[x.a] - depth[l]), fd(x.b,depth[x.b]-depth[l]));
	  		out[x.ind] = t;
			continue;
		}
		int l = root->query(pos[x.a]);
		out[x.ind]=l;
	}
	for (int i=0;i<E;++i)cout<<out[i]<<'\n';
}