/*
 *  Dominator tree in O(M log(N)/log(2+M/N)) time, O(M+N) space
 *  Algorithm by T.Lengauer and R.E.Tarjan
 *  This is essentially the directed version of articulation points
 */

#include <bits/stdc++.h>
using namespace std;

struct Dominator{
    struct min_DSU{
        int N;
        vector<int> par, val;
        vector<int> const&semi;
        min_DSU(int _N, vector<int> const&semidom):N(_N),par(N, -1),val(N), semi(semidom){
            iota(val.begin(), val.end(), 0);
        }
        void comp(int x){
            if(par[par[x]]!=-1){
                comp(par[x]);
                if(semi[val[par[x]]]<semi[val[x]]){
                    val[x] = val[par[x]];
                }
                par[x]=par[par[x]];
            }
        }
        int f(int x){
            if(par[x]==-1){
                return x;
            }
            comp(x);
            return val[x];
        }
        void link(int x, int p){
            par[x] = p;
        }
    };
    int N;
    vector<vector<int> > G, rG;
    vector<int> immediate_dominator, order;
    vector<vector<int> > dominated;
    Dominator(int _N):N(_N), G(N), rG(N){}
    void add_edge(int a, int b){
        G[a].emplace_back(b);
        rG[b].emplace_back(a);
    }
    vector<int> calc_dominators(int S){
        immediate_dominator.assign(N, -1);
        vector<int> par(N, -1), cur_edge(N, 0), semidom(N, -1);
        vector<vector<int> > bucket(N);
        stack<int> s;
        s.emplace(S);
        while(!s.empty()){
            int a=s.top();s.pop();
            if(semidom[a]==-1){
                semidom[a] = order.size();
                order.emplace_back(a);
            }
            for(int &i=cur_edge[a];i<(int)G[a].size();++i){
                if(semidom[G[a][i]]==-1){
                    s.push(a);
                    par[G[a][i]]=a;
                    s.push(G[a][i]);
                    break;
        }   }   }
        min_DSU uni(N, semidom);
        for(int i=(int)order.size()-1;i>0;--i){
            int w=order[i];
            for(int f:rG[w]){
                int oval = semidom[uni.f(f)];
                if(oval>=0 && semidom[w]>oval) semidom[w] = oval;
                //semidom[w] = min(semidom[w], owal);
            }
            bucket[order[semidom[w]]].push_back(w);
            uni.link(w, par[w]);
            while(!bucket[par[w]].empty()){
                int v = bucket[par[w]].back(); bucket[par[w]].pop_back();
                int u=uni.f(v);
                if(semidom[u] < semidom[v]) immediate_dominator[v] = u;
                else immediate_dominator[v] = par[w];
            }
        }
        for(int i=1;i<(int)order.size();++i){
            int w=order[i];
            //cerr << (char)(w==0?'R' : 'A'+w-1) << "," << w << ":" << (char)(order[semidom[w]]==0?'R' : 'A' + order[semidom[w]]-1) << "," <<  semidom[w] << "\n";
            if(immediate_dominator[w] != order[semidom[w]]){
                immediate_dominator[w] = immediate_dominator[immediate_dominator[w]];
            }
        }
        immediate_dominator[S]=-1;
        return immediate_dominator;
    }
};
/*
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dominator_tree.hpp>
using namespace boost;

typedef adjacency_list<listS, listS, bidirectionalS, property<vertex_index_t, std::size_t>, no_property> G;
void test(int N, vector<pair<int, int> > const&ed){
    G g(ed.begin(), ed.end(), N);

    typedef graph_traits<G>::vertex_descriptor Vertex;
    typedef property_map<G, vertex_index_t>::type IndexMap;
    typedef iterator_property_map<vector<Vertex>::iterator, IndexMap> PredMap;

    vector<Vertex> domTreePredVector, domTreePredVector2;
    IndexMap indexMap(get(vertex_index, g));
    graph_traits<G>::vertex_iterator uItr, uEnd;
    int j = 0;
    for (tie(uItr, uEnd) = vertices(g); uItr != uEnd; ++uItr, ++j)
    {
       put(indexMap, *uItr, j);
    }

    // Lengauer-Tarjan dominator tree algorithm
    domTreePredVector =  vector<Vertex>(num_vertices(g), graph_traits<G>::null_vertex());
    PredMap domTreePredMap =  make_iterator_property_map(domTreePredVector.begin(), indexMap);

    lengauer_tarjan_dominator_tree(g, vertex(0, g), domTreePredMap);

    vector<int> idom(num_vertices(g));
    for (tie(uItr, uEnd) = vertices(g); uItr != uEnd; ++uItr)
    {
      if (get(domTreePredMap, *uItr) != graph_traits<G>::null_vertex())
        idom[get(indexMap, *uItr)] = get(indexMap, get(domTreePredMap, *uItr));
      else
        idom[get(indexMap, *uItr)] = -1;//(numeric_limits<int>::max)();
    }
    copy(idom.begin(), idom.end(), ostream_iterator<int>(cerr, " "));
    cerr << "\n";

}*/
using ll = long long;

vector<ll> dijkstras(vector<vector<pair<int, ll> > > const&g, int s){
    vector<ll> ret(g.size(), numeric_limits<ll>::max()/2);
    ret[s]=0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int> > > pq;
    pq.emplace(ret[s], s);
    while(!pq.empty()){
        ll curd; int c;
        tie(curd, c) = pq.top();
        pq.pop();
        if(curd!=ret[c]) continue;
        for(auto const&e:g[c]){
            if(ret[e.first]>ret[c]+e.second){
                ret[e.first] = ret[c]+e.second;
                pq.emplace(ret[e.first], e.first);
            }
        }
    }
    return ret;
}

namespace FIO{
    char buf[32*1042|1];
    int bc=0, be=0;
    char gc(){
        if(bc>=be){
            be = fread(buf, 1, sizeof(buf)-1, stdin);
            buf[be] = bc = 0;
        }
        return buf[bc++];
    }
    void readint(){}
    template<typename T, typename ...S>
    void readint(T &a, S& ...b){
        a=0;
        int x=gc();
        while(x<'0' || x>'9') x=gc();
        while(x>='0' && x<='9'){
            a = a*10+x-'0';
            x=gc();
        }
        readint(b...);
    }
}
using FIO::readint;

signed CF757F(){
    int n, m, S;
    readint(n, m, S);
    vector<vector<pair<int, ll> > > G(n+1);
    while(m--){
        int a, b, c;
        readint(a, b, c);
        G[a].emplace_back(b, c);
        G[b].emplace_back(a, c);
    }
    vector<ll> dist = dijkstras(G, S);
    Dominator D(n+1);
    for(int i=0;i<=n;++i){
        for(auto e:G[i]){
            if(dist[e.first] == dist[i] + e.second){
                D.add_edge(i, e.first);
            }
        }
    }
    vector<int> id = D.calc_dominators(S);

    vector<int> hit(n+1, 0);
    for(int i=(int)D.order.size()-1;i>0;--i){
        int e = D.order[i];
        hit[id[e]]+=++hit[e];
    }
    hit[S] = 0;
    int ans = *max_element(hit.begin(), hit.end());
    printf("%d\n", ans);
    return 0;


}

int main(){
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    #endif // LOCAL_RUN
    return CF757F();
    cerr << "go\n";
    int N, M, a, b;
    while(cin >> N >> M && N){
        vector<pair<int, int> > ed;
        Dominator D(N);
        while(M--){
            cin >> a >> b;
            D.add_edge(a, b);
            ed.emplace_back(a, b);
        }
        //test(N, ed);
        vector<int> id = D.calc_dominators(0);
        copy(id.begin(), id.end(), ostream_iterator<int>(cerr, " "));
        cerr << "\n";
    }

}