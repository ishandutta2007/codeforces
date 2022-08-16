#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 100005, maxm = 250005;
int N, M, S, T;

typedef int flow_t;

struct Edge {
	int to, next;
	flow_t f;
	void set(int _to, flow_t _f, int _next){
	  to=_to;
	  f=_f;
	  next=_next;
	}
};
Edge edges[maxm * 2];
int edge_list_begin[maxn], lastEdge;
inline void add_edge(int a, int b, flow_t f) {
  if(a==b) return;
	edges[lastEdge].set(b, f, edge_list_begin[a]);
	edge_list_begin[a] = lastEdge++;
	edges[lastEdge].set(a, 0, edge_list_begin[b]);	//Monodirectional edge
	//edges[lastEdge].set(a, f, edge_list_begin[b]);	//Bidirectional edge
	edge_list_begin[b] = lastEdge++;
}
int h[maxn];

int q[maxn], v[maxn];
inline bool layer() {
  int f = 0, b = 0;
  fill(h, h+N+5, -1);
  fill(v, v+N+5, 0);
	h[T] =0;
	q[b++] = T;
	while (f < b) {//	initial BFS
		int u = q[f++];
		for (int p = edge_list_begin[u]; p; p = edges[p].next) {
			int v = edges[p].to;
			if (h[v] == -1 && edges[p ^ 1].f > 0) {
				h[v] = h[u] + 1;
				q[b++] = v;
			}
		}
	}
	return h[S]!=-1;
}
flow_t max_flow() {
  flow_t ret = 0;
  int t=0;
	while (layer()) {
    for(int se=edge_list_begin[S];se;se=edges[se].next){
      q[++t]=se;
      while(t){
        int u=edges[q[t]].to;
        if(u!=T){
            for(int e=edge_list_begin[u];e;e=edges[e].next){
              if(!v[edges[e].to] && h[edges[e].to] == h[u]-1 && edges[e].f){
                q[++t]=e;
                break;
              }
            }
            if(edges[q[t]].to==u){
              v[u]=1;
              --t;
            }
        } else {
          int bo = q[1];
          for(int i=1;i<=t;++i){
            if(edges[q[i]].f < edges[bo].f){
              bo=q[i];
            }
          }
          flow_t fl = edges[bo].f;
          ret+=fl;
          for(int i=1;i<=t;++i){
            edges[q[i]].f-=fl;
            edges[q[i]^1].f+=fl;
          }
          while(q[t]!=bo){
            --t;
          }
          --t;
        }
      }
    }
	}
	return ret;
}



int sold(){
  int mid;
	scanf("%d%d", &mid, &M);
	N=2*mid;
	lastEdge = 2;
	S = N+1, T = N+2;
	int u, v, c;
	int tot=0, tot2=0;
	for(int i=1;i<=mid;++i){
		scanf("%d", &c);
		tot+=c;
		add_edge(S, i, c);
		add_edge(i, i+mid, c);
	}
	for(int i=1;i<=mid;++i){
		scanf("%d", &c);
		tot2+=c;
		add_edge(i+mid, T, c);
	}
	for (int i = 1; i <= M; ++i) {
		scanf("%d%d", &u, &v);
		add_edge(u, mid+v, 100*N);
		add_edge(v, mid+u, 100*N);
	}
	N+=10;
	int fl = max_flow();
	if(fl!=tot||fl!=tot2){
    cout << "NO\n";
    return 0;
	}
	cout << "YES\n";
	vector<vector<int> > out(mid+1, vector<int> (mid+1, 0));
	for(int i=2;i<lastEdge;i+=2){
    if(edges[i].to<=2*mid && edges[i^1].to<=2*mid){
      out[edges[i^1].to][edges[i].to-mid] = edges[i^1].f;
    }
	}
	for(int i=1;i<=mid;++i){
    for(int j=1;j<=mid;++j){
      printf("%d ", out[i][j]);
    }
    printf("\n");
	}
	return 0;
}

int main() {
  return sold();
  //freopen("in.txt", "r", stdin);
	int mid;
	scanf("%d%d%d", &mid,&N, &M);
	N+=mid;
	lastEdge = 2;
	S = N+1, T = N+2;
	int u, v;
	for (int i = 1; i <= M; ++i) {
		scanf("%d%d", &u, &v);
		//add_edge(u, mid+v, 1);
		add_edge(u, v, 1);
	}
	for(int i=1;i<=mid;++i){
		add_edge(S, i, 1);
	}
	for(int i=mid+1;i<=N;++i){
		add_edge(i, T, 1);
	}
	printf("%d\n",max_flow());
	return 0;
}