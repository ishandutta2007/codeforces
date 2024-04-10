#pragma GCC optimize("O3","Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>

#define int long long

using namespace std;

struct DSU_WITH_ROLLBACKS
{
    struct dsu_save
    {
        int u, urank, v, vrank, comps;
        bool bipart;
    };

    stack<dsu_save> op;

    vector<int> rnk;
    vector<bool> col;
    bool bipartite;
    int comps;

    DSU_WITH_ROLLBACKS()
    {

    }

    DSU_WITH_ROLLBACKS(int N)
    {
        init(N);
    }

    void init(int N)
    {
        rnk.clear();
        col.clear();
        while(!op.empty())op.pop();
        rnk.resize(N);
        col.resize(N);
        for(int i = 0 ; i < N ; i++)
        {
            rnk[i] = 1;
            col[i] = false;
        }
        bipartite = true;
        comps = N;
    }

    pair<int,bool> find(int x)
    {
        if(rnk[x] > 0)return {x, col[x]};
        pair<int,bool> tp = find(-rnk[x]);
        tp.second ^= col[x];
        return tp;
    }

    void join(int a, int b)
    {
        pair<int,bool> ta = find(a), tb = find(b);
        a = ta.first;
        b = tb.first;
        op.push({a, rnk[a], b, rnk[b], comps, bipartite});
        if(a == b)
        {
            if(ta.second == tb.second)bipartite = false;
            return;
        }
        comps--;
        if(rnk[a] < rnk[b])swap(a,b);
        rnk[a] += rnk[b];
        rnk[b] = -a;
        col[b] = col[b]^(ta.second == tb.second);
    }

    void rollback()
    {
        if(op.empty())return;
        dsu_save x = op.top();
        op.pop();
        comps = x.comps;
        bipartite = x.bipart;
        rnk[x.u] = x.urank;
        col[x.u] = false;
        rnk[x.v] = x.vrank;
        col[x.v] = false;
    }
};

const int MAXN = 5e5 + 100;

vector<int> arr[MAXN];

vector<int> res;

template<typename T, typename F, typename D>
struct ROLLBACK_TRICK
{
    vector<vector<T>> ST;
    int N;

    void add_to_tree(int nodo, int l, int r, int a, int b, T qu)
    {
        if(r < a || l > b)return;
        if(a <= l && r <= b)
        {
            ST[nodo].push_back(qu);
            return;
        }
        int mid = (l+r)/2;
        add_to_tree(nodo*2, l, mid, a, b, qu);
        add_to_tree(nodo*2+1, mid+1, r, a, b, qu);
    }

    void add_query(T qu, int l, int r)
    {
        add_to_tree(1, 0, N-1, l, r, qu);
    }

    void dfs(int nodo, int l, int r, D &DS)
    {
        for(auto x : ST[nodo])DS.join(x.first, x.second);
        if(l == r)
        {
        	for(auto x : arr[l])
        	{
        		res.push_back(DS.rnk[DS.find(x).first]);
        	}
        }
        else
        {
            int mid = (l+r)/2;
            dfs(nodo*2, l, mid, DS);
            dfs(nodo*2+1, mid+1, r, DS);
        }
        for(int i = 0 ; i < ST[nodo].size() ; i++)DS.rollback();
    }

    void solve(int tn, vector<T> vect, vector<pair<int,int>> querys, D &DS)
    {
        assert(vect.size() == querys.size());

        N = tn;

        ST.clear();
        ST.resize(4*(N+4));

        for(int i = 0 ; i < vect.size() ; i++)
        {
            add_query(vect[i], querys[i].first, querys[i].second);
        }

        dfs(1, 0, N-1, DS);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, Q, K;
    cin >> N >> Q >> K;

    DSU_WITH_ROLLBACKS DSU(N+1);

    vector<pair<int,int>> qu;

    vector<pair<int,int>> vect;

    deque<vector<pair<pair<int,int>,int>>> D;

    vector<pair<pair<int,int>,int>> temp;

    int cont = 0;

    for(int i = 1 ; i <= Q ; i++)
    {
    	int tp;
    	cin >> tp;

    	if(tp == 1)
    	{
    		int a, b;
    		cin >> a >> b;
    		temp.push_back({{a,b},cont});
    	}
    	if(tp == 2)
    	{
    		int q;
    		cin >> q;
    		arr[cont].push_back(q);
    		cont++;
    	}
    	if(tp == 3)
    	{
    		D.push_back(temp);
    		temp.clear();

    		if(D.size() == K)
    		{
    			for(auto x : D.front())
    			{
    				qu.push_back({x.second,cont});
    				vect.push_back({x.first.first,x.first.second});
    			}
    			D.pop_front();
    		}
    		cont++;
    	}
    }
D.push_back(temp);
    while(D.size())
    {
    	for(auto x : D.front())
		{
			qu.push_back({x.second,cont});
			vect.push_back({x.first.first,x.first.second});
		}
		D.pop_front();
    }

    cont++;

    ROLLBACK_TRICK<pair<int,int>, int, DSU_WITH_ROLLBACKS> RT;

    RT.solve(cont, vect, qu, DSU);

    for(auto x : res)
    {
    	cout << x << '\n';
    }

    return 0;
}