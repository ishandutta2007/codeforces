#include <bits/stdc++.h>

// #define int long long

using namespace std;

#ifdef LOCAL 
#include "/media/brayand/BrayanD/debugger.h"
#else
#define db(...) false
#define dbl(...) false
#define dbg(...) false
#define dbm(...) false
#define dbs(...) false
#define dbas(...) false
#endif

template<typename T, typename F>
struct AHO_CORASICK
{
    const int ALPHA = 26;

    int cv(F c)
    {
        return c-'0';
    }

    vector<pair<int,int>> lim;
    vector<vector<int>> glink;
    vector<vector<int>> words;
    vector<vector<int>> tgo;
    vector<int> pt_string;
    vector<int> dict_link;
    vector<int> vtime;
    vector<int> link;
    vector<int> abi;
    vector<int> ch;
    vector<int> p;

    int cant_string = 0;
    int sz = 0;

    bool ok_match = false;
    bool ok_link_tree = false;

    void init()
    {
        lim.clear();
        glink.clear();
        words.clear();
        tgo.clear();
        pt_string.clear();
        dict_link.clear();
        vtime.clear();
        link.clear();
        abi.clear();
        ch.clear();
        p.clear();

        cant_string = 0;
        sz = 0;

        ok_match = false;
        ok_link_tree = false;

        new_node(-1,-1);
    }

    void build(vector<T> &vect)
    {
        init();
        for(int i = 0 ; i < vect.size() ; i++)
        {
            add_string(vect[i]);
        }
    }

    int size()
    {
        return sz;
    }

    void new_node(int tp, int tch)
    {
        sz++;
        tgo.push_back(vector<int>(ALPHA,-1));
        dict_link.push_back(-1);
        words.emplace_back();
        link.push_back(-1);
        ch.push_back(tch);
        p.push_back(tp);
    }

    AHO_CORASICK()
    {
        init();
    }

    void add_string(T cad)
    {
        int pt = 0;
        for(int i = 0 ; i < cad.size() ; i++)
        {
            int tch = cv(cad[i]);
            if(tgo[pt][tch] == -1)
            {
                tgo[pt][tch] = sz;
                new_node(pt, tch);
            }
            pt = tgo[pt][tch];
        }
        words[pt].push_back(pt_string.size());
        pt_string.push_back(pt);
    }

    void build_link_tree()
    {
        ok_link_tree = true;
        glink.resize(sz);
        for(int i = 1 ; i < sz ; i++)
        {
            glink[get_link(i)].push_back(i);
        }
    }

    void build_match()
    {
        ok_match = true;
        if(ok_link_tree == false)build_link_tree();
        vtime.resize(sz);
        lim.resize(sz);
        abi.resize(sz+1);
        int ct = 0;
        function<void(int)> DFS = [&](int nodo)
        {
            vtime[nodo] = ++ct;
            for(auto v : glink[nodo])
            {
                DFS(v);
            }
            lim[nodo] = {vtime[nodo], ct};
        };
        DFS(0);
    }

    void abi_update(int x, int v)
    {
        while(x < abi.size())
        {
            abi[x] += v;
            x += x&-x;
        }
    }

    int abi_query(int x)
    {
        int res = 0;
        while(x)
        {
            res += abi[x];
            x -= x&-x;
        }
        return res;
    }

    int abi_range(int a, int b)
    {
        return abi_query(b) - abi_query(a-1);
    }

    vector<int> match(vector<T> vcad)
    {
        if(ok_match == false)build_match();
        vector<int> ups;
        for(auto cad : vcad)
        {
            int pt = 0;
            for(int i = 0 ; i < cad.size() ; i++)
            {
                pt = go(pt, cad[i]);
                abi_update(vtime[pt], 1);
                ups.push_back(vtime[pt]);
            }
        }
        vector<int> res(pt_string.size());
        for(int i = 0 ; i < pt_string.size() ; i++)
        {
            res[i] = abi_range(lim[pt_string[i]].first, lim[pt_string[i]].second);
        }
        for(auto x : ups)
        {
            abi_update(x, -1);
        }
        return res;
    }

    vector<int> match_offline(vector<T> vcad)
    {
        if(ok_link_tree == false)build_link_tree();
        vector<int> dp(sz);
        for(auto cad : vcad)
        {
            int pt = 0;
            for(int i = 0 ; i < cad.size() ; i++)
            {
                pt = go(pt, cad[i]);
                dp[pt]++;
            }
        }
        function<void(int)> DFS = [&](int nodo)
        {
            for(auto v : glink[nodo])
            {
                DFS(v);
                dp[nodo] += dp[v];
            }
        };
        DFS(0);
        vector<int> res(pt_string.size());
        for(int i = 0 ; i < pt_string.size() ; i++)
        {
            res[i] = dp[pt_string[i]];
        }
        return res;
    }

    int get_dictionary_link(int nodo)
    {
        if(dict_link[nodo] == -1)
        {
            if(nodo == 0 || p[nodo] == 0)dict_link[nodo] = 0;
            else
            {
                int v = get_link(nodo);
                if(words[v].size())dict_link[nodo] = v;
                else dict_link[nodo] = get_dictionary_link(v);
            }
        }
        return dict_link[nodo];
    }

    int get_link(int nodo)
    {
        if(link[nodo] == -1)
        {
            if(nodo == 0 || p[nodo] == 0)link[nodo] = 0;
            else link[nodo] = move(get_link(p[nodo]), ch[nodo]);
        }
        return link[nodo];
    }

    int go(int nodo, F tch)
    {
        return move(nodo, cv(tch));
    }

    int move(int nodo, int tch)
    {
        if(tgo[nodo][tch] == -1)
        {
            tgo[nodo][tch] = (nodo == 0) ? 0 : move(get_link(nodo),tch);
        }
        return tgo[nodo][tch];
    }
};

const int MAXN = 550;

short dp[MAXN][MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0 ; i < MAXN ; i++)
    {
    	for(int j = 0 ; j < MAXN ; j++)
    	{
    		for(int k = 0 ; k < MAXN ; k++)
    		{
    			dp[i][j][k] = 1000;
    		}
    	}
    }

	int N, M;
	cin >> N >> M;

	string cad;
	string cad2;

	cin >> cad >> cad2;

	AHO_CORASICK<string,char> AC;

	AC.add_string(cad2);

	dp[0][0][0] = 0;

	for(int i = 0 ; i < N ; i++)
	{
		for(int j = 0 ; j <= N ; j++)
		{
			for(int k = 0 ; k < AC.sz ; k++)
			{
				int pt0 = AC.go(k,'0');
				int pt1 = AC.go(k,'1');

				int v1 = 0;
				int v2 = 0;

				if(cad[i] != '0')v1 = 1;
				if(cad[i] != '1')v2 = 1;

				if(pt0 == AC.sz-1)
				{
					dp[i+1][j+1][pt0] = min(dp[i+1][j+1][pt0], short(dp[i][j][k] + v1));
				}
				else
				{
					dp[i+1][j][pt0] = min(dp[i+1][j][pt0], short(dp[i][j][k] + v1));
				}

				if(pt1 == AC.sz-1)
				{
					dp[i+1][j+1][pt1] = min(dp[i+1][j+1][pt1], short(dp[i][j][k] + v2));
				}
				else
				{
					dp[i+1][j][pt1] = min(dp[i+1][j][pt1], short(dp[i][j][k] + v2));
				}

				// dbs(dp,i+1,j,pt1);
			}
		}
	}

	for(int i = 0 ; i <= N-M+1 ; i++)
	{
		int men = 1000;
		for(int j = 0 ; j < AC.sz ; j++)
		{
			men = min((short)men, dp[N][i][j]);
		}

		if(men == 1000)
		{
			cout << -1 << " ";
		}
		else
		{
			cout << men << " ";
		}
	}

	cout << '\n';

    return 0;
}