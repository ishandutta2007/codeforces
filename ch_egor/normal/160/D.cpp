//just for test one moment

#include <iostream>
#include <vector>
#include <cstdio>
#include <stack>
#include <tuple>
#include <map>
#include <algorithm>

using namespace std;

class persistent_array
{
    vector<int> a;
    stack<pair<int, int> > st;
  public:
    persistent_array(int _n, int d = 0)
    {
        a.resize(_n, d);
        st.push(make_pair(-1, -1));
    }
    int get(int i)
    {
        return a[i];
    }
    void set(int i, int v)
    {
        st.push({i, a[i]});
        a[i] = v;
    }
    void save_state()
    {
        st.push(make_pair(-1, -1));
    }
    void restore_state()
    {
        while (st.top().first != -1)
        {
            a[st.top().first] = st.top().second;
            st.pop();
        }
        st.pop();
    }
};

class persistent_dsu
{
    persistent_array par, rank;
    int get(int v)
    {
        if (v != par.get(v))
        {
            par.set(v, get(par.get(v)));
        }
        return par.get(v);
    }
    void merge(int u, int v)
    {
        u = get(u);
        v = get(v);
        if (rank.get(v) < rank.get(u))
            swap(u, v);
        if (u != v)
        {
            par.set(u, v);
            rank.set(v, max(rank.get(v), rank.get(u) + 1));
        }
    }
  public:
    persistent_dsu(int n) : par(n), rank(n)
    {
        for (int i = 0; i < n; i++)
        {
            par.set(i, i);
            rank.set(i, 1);
        }
    }
    bool in_one(int u, int v)
    {
        return get(u) == get(v);
    }
    void unite(int u, int v)
    {
        merge(u, v);
    }
    void save_state()
    {
        par.save_state();
        rank.save_state();
    }
    void restore_state()
    {
        par.restore_state();
        rank.restore_state();
    }
};

class dynamic_connectivity_engine
{
    vector<tuple<int, int, int> > qs;
    vector<vector<pair<int, int> > > edges;
    void add_edge(int v, int L, int R, int l, int r, int u, int _v)
    {
        if (r <= L || R <= l)
            return;
        else if (l <= L && R <= r)
            edges[v].push_back({u, _v});
        else
        {
            add_edge(2 * v + 1, L, (L + R) >> 1, l, r, u, _v);
            add_edge(2 * v + 2, (L + R) >> 1, R, l, r, u, _v);
        }
    }
    void ans(int v, int L, int R, vector<bool>& answs, persistent_dsu& dsu)
    {
        if (L == R - 1)
        {
            for (auto p : edges[v])
                dsu.unite(p.first, p.second);
            if (get<0>(qs[L]))
                answs.push_back(dsu.in_one(get<1>(qs[L]), get<2>(qs[L])));
        }
        else
        {
            for (auto p : edges[v])
                dsu.unite(p.first, p.second);
            dsu.save_state();
            ans(2 * v + 1, L, (L + R) >> 1, answs, dsu);
            dsu.restore_state();
            dsu.save_state();
            ans(2 * v + 2, (L + R) >> 1, R, answs, dsu);
            dsu.restore_state();
        }
    }
    int n;
  public:
    dynamic_connectivity_engine(int _n, vector<tuple<int, int, int> > queries)
    {
        qs = queries;
        n = _n;
        edges.resize(4 * qs.size());
        map<pair<int, int>, int> last;
        for (int i = 0; i < (int)queries.size(); i++)
        {
/*            if ((get<1>(queries[i]) == 2 && get<2>(queries[i]) == 3) ||
                (get<1>(queries[i]) == 4 && get<2>(queries[i]) == 2))
            {
                cout << get<0>(queries[i]) << " " << get<1>(queries[i]) << " " << get<2>(queries[i]) << " " << i << endl;
            }*/
            if (!get<0>(queries[i]))
            {
                pair<int, int> p = {get<1>(queries[i]), get<2>(queries[i])};
                if (!last.count(p) || last[p] == -1)
                {
                    last[p] = i;
                }
                else
                {
                    add_edge(0, 0, qs.size(), last[p], i, p.first, p.second);
                    last[p] = -1;
                }
            }
        }
        for (auto p : last)
        {
            if (p.second != -1)
            {
                add_edge(0, 0, qs.size(), last[p.first], qs.size(), p.first.first, p.first.second);
            }
        }
    }
    vector<bool> ans()
    {
        vector<bool> answ;
        persistent_dsu dsu(n);
        ans(0, 0, qs.size(), answ, dsu);
        return answ;
    }
};

struct edge
{
    int u, v, w, i;
    edge(int _u, int _v, int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
    edge() {}
    bool operator<(const edge& other)
    {
        return w < other.w;
    }
};

istream& operator>>(istream& is, edge& e)
{
    is >> e.u >> e.v >> e.w;
    e.u--; e.v--;
    return is;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<edge> es(m);
    for (int i = 0; i < m; i++)
    {
        cin >> es[i]; es[i].i = i;
    }
    sort(es.begin(), es.end());
    int l = 0, r = 0;
    vector<tuple<int, int, int> > qs;
    vector<pair<bool, int> > of;
    while (l < m)
    {
        while (r < m && es[r].w == es[l].w)
            r++;
        
        for (int i = l; i < r; i++)
        {
            qs.push_back(make_tuple(1, es[i].u, es[i].v));
            of.push_back({0, es[i].i});
        }
        for (int i = l; i < r; i++)
            qs.push_back(make_tuple(0, es[i].u, es[i].v));
        for (int i = l; i < r; i++)
        {
            qs.push_back(make_tuple(0, es[i].u, es[i].v));
            qs.push_back(make_tuple(1, es[i].u, es[i].v));
            of.push_back({1, es[i].i});
            qs.push_back(make_tuple(0, es[i].u, es[i].v)); 
        }
        l = r;
    }
    dynamic_connectivity_engine dcp(n, qs);
    vector<bool> dcpa = dcp.ans();
    vector<bool> a_l_one(m), any(m);
    for (int i = 0; i < 2 * m; i++)
    {
        if (of[i].first == 0)
            a_l_one[of[i].second] = !dcpa[i];
        else
            any[of[i].second] = !dcpa[i];
    }
    for (int i = 0; i < m; i++)
    {
        if (!a_l_one[i])
            cout << "none" << endl;
        else if (!any[i])
            cout << "at least one" << endl;
        else
            cout << "any" << endl;
    }
    return 0;
}