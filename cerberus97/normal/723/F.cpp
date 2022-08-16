#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define source first
#define target second

const int N = 2e5 + 5, INF = 2147483647;

vector <vector <pii> > subGraph[N];
vector <int> g[N], ans[N], temp[N];

int ds, dt;
bool seen[N], visited[N], conn = false;

void buildSubGraph(int st, int s, int t, int x, bool *seen)
{
	vector <pii> es, et, e;
	queue <int> q;

	q.push(st);
	seen[st] = true;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (auto &i : g[cur])
		{
			if (!seen[i])
			{
				if (i == s)
					es.push_back({cur, s});

				else if (i == t)
					et.push_back({cur, t});

				else
				{
					e.push_back({cur, i});
					seen[i] = true;
					q.push(i);
				}
			}
		}
	}

	subGraph[x].push_back(es);
	subGraph[x].push_back(et);
	subGraph[x].push_back(e);
}

bool buildMST(int x, int s, int t, int n)
{
	queue <pii> q;
	int startNode = -1;

	for (auto &i : subGraph[x][2])
	{
		temp[i.first].push_back(i.second);
		temp[i.second].push_back(i.first);

		startNode = i.first;
	}


	if (subGraph[x][1].empty())
    {
    	if (ds <= 0)
    		return false;

    	--ds;

    	ans[subGraph[x][0][0].first].push_back(s);
    	ans[s].push_back(subGraph[x][0][0].first);
    }

    else if (subGraph[x][0].empty())
    {
    	if (dt <= 0)
    		return false;

    	--dt;

    	ans[subGraph[x][1][0].first].push_back(t);
    	ans[t].push_back(subGraph[x][1][0].first);
    }

    else
    {
	    if (ds == 0 and dt == 0)
	    	return false;

	    if (!conn)
	    {
	    	if (!ds or !dt)
	    		return false;

	    	conn = true;

	    	--ds;
	    	--dt;

	    	ans[subGraph[x][0][0].first].push_back(s);
	    	ans[s].push_back(subGraph[x][0][0].first);
	    	ans[subGraph[x][1][0].first].push_back(t);
	    	ans[t].push_back(subGraph[x][1][0].first);
	    }

	    else
	    {
		    if (ds > dt)
		    {
		    	--ds;

		    	ans[subGraph[x][0][0].first].push_back(s);
		    	ans[s].push_back(subGraph[x][0][0].first);
		    }

		    else
		    {
		    	--dt;

		    	ans[subGraph[x][1][0].first].push_back(t);
		    	ans[t].push_back(subGraph[x][1][0].first);
		    }
	    }
    }

    if (startNode == -1)
    	return true;

    visited[startNode] = true;

    for (auto &i : temp[startNode])
    {
        q.push({startNode, i});
    }


    while (!q.empty())
    {
        pii cur = q.front();
        q.pop();

        if (visited[cur.target])
            continue;

        visited[cur.target] = true;

        ans[cur.source].push_back(cur.target);
        ans[cur.target].push_back(cur.source);

        for (auto &i : temp[cur.target])
        {
            if (!visited[i])
            {
                q.push({cur.target, i});
            }
        }
    }

    return true;
}

int main()
{
	int n, m;
	cin >> n >> m;

	int u,v;

	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int s, t;
	cin >> s >> t >> ds >> dt;

	int x = 0;

	for (int i = 1; i <= n; ++i)
	{
		if (i == s or i == t)
			continue;

		if (seen[i])
			continue;

		buildSubGraph(i, s, t, x++, seen);
	}

	// for (auto &i : subGraph[0][2])
	// 	cout << i.first << ' ';

	// return 0;

	bool f = true;

	for (int i = 0; i < x; ++i)
	{
		if (subGraph[i][0].empty() or subGraph[i][1].empty())
		{
			f = f and buildMST(i, s, t, n);

			if (!f)
				break;
		}
	}

	if (!f)
	{
		cout << "No";
		return 0;
	}

	for (int i = 0; i < x; ++i)
	{
		if (!subGraph[i][0].empty() and !subGraph[i][1].empty())
		{
			f = f and buildMST(i, s, t, n);

			if (!f)
				break;
		}
	}


	if (!f)
	{
		cout << "No";
		return 0;
	}

	if (!conn)
	{
		for (auto &i : g[s])
		{
			if (i == t)
			{
				conn = true;
				--ds;
				--dt;
				ans[s].push_back(t);
				ans[t].push_back(s);
				break;
			}
		}
	}

	if (!conn)
	{
		for (auto &i : g[t])
		{
			if (i == s)
			{
				conn = true;
				--ds;
				--dt;
				ans[s].push_back(t);
				ans[t].push_back(s);
				break;
			}
		}
	}

	if (!conn or ds < 0 or dt < 0)
	{
		cout << "No";
		return 0;
	}

	cout << "Yes\n";

	for (int i = 1; i <= n; ++i)
	{
		for (auto &j : ans[i])
		{
			if (i < j)
				cout << i << ' ' << j << '\n';
		}
	}
}