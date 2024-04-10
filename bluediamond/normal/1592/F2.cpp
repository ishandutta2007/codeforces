#include <bits/stdc++.h>

using namespace std;
int sum=0,last=0;
typedef long long ll;

struct Flow {
	const int INF = (int)1e9 + 7;
	int n;

	struct Edge {
		int to, cap;
	};

	vector<Edge> edges;
	vector<vector<int>> g;
	vector<int> level, pt;

	Flow(int n) :
		n(n),
		g(n),
		level(n),
		pt(n) {
	}

	void addEdge(int a, int b, int c) {
		a--;
		b--;
		assert(0 <= a && a < n);
		assert(0 <= b && b < n);
		g[a].push_back((int)edges.size());
		g[b].push_back((int)edges.size() + 1);
		edges.push_back({ b, c });
		edges.push_back({ a, 0 });
	}

	int dfs(int a, int cur) {
		if (a == n - 1 || cur == 0) return cur;

		while (pt[a] < (int)g[a].size()) {
			int i = g[a][pt[a]++];
			int b = edges[i].to, cap = edges[i].cap;
			if (level[b] == 1 + level[a] && cap) {
				int x = dfs(b, min(cur, cap));
				if (x) {
					pt[a]--;

					edges[i].cap -= x;
					edges[i ^ 1].cap += x;

					return x;
				}
			}
		}

		return 0;
	}

	int get() {
		int sol = 0, ret=sum+last;
		while (1) {
			for (int i = 0; i < n; i++) level[i] = -1, pt[i] = 0;
			level[0] = 0;
			queue<int> q;
			q.push(0);
			while (!q.empty()) {
				int a = q.front();
				q.pop();
				for (auto& i : g[a]) {
					if (edges[i].cap&&level[edges[i].to]==-1) {
						level[edges[i].to] = 1 + level[a];
						q.push(edges[i].to);
					}
				}
			}
			if (level[n - 1] == -1) break;
			while (1) {
				int x = dfs(0, INF);
				if (!x) break;
				sol += x;
				sum-=3;
				last^=1;
				ret=min(ret,2*sol+sum+last);
			}
		}
		return ret;
	}
};

const int N=500+7;
int n,m,a[N][N],v[N][N];

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  cin>>n>>m;
  for (int i=1;i<=n;i++) {
    string s;
    cin>>s;
    for (int j=1;j<=m;j++) {
      a[i][j]=(s[j-1]!='W');
    }
  }
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      v[i][j]=a[i][j]^a[i+1][j]^a[i][j+1]^a[i+1][j+1];
    }
  }

  Flow flow(1+n+m+1);

  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      a[i][j]=v[i][j];
    }
  }
  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      sum+=v[i][j];
    }
  }
  sum-=v[n][m];

  for (int i=1;i<=n;i++) {
    flow.addEdge(1,1+i,1);
  }
  for (int i=1;i<=m;i++) {
    flow.addEdge(1+n+i,1+n+m+1,1);
  }

  for(int i=1;i<n;i++) {
    for (int j=1;j<m;j++) {
      if (v[i][j]&&v[i][m]&&v[n][j]){
        flow.addEdge(1+i,1+n+j,1);
        ///cout<<i<<" "<<j<<"\n";
      }
    }
  }

  last=v[n][m];
  cout<<flow.get()<<"\n";

}