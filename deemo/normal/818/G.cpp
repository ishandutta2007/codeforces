#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e4 + 10;
const int XX = 1e8;
const int MAXE = 2e7;
const int MAXVAL = 1e5 + 10;
const int INF = 1e4;

int n, a[MAXN];
int from[MAXE], to[MAXE], cap[MAXE], ww[MAXE], prv[MAXE], head[MAXN], ec;

void addEdge(int u, int v, int uv, int w, int vu = 0){
	from[ec] = u, to[ec] = v, cap[ec] = uv, ww[ec] = w, prv[ec] = head[u], head[u] = ec++;
	from[ec] = v, to[ec] = u, cap[ec] = vu, ww[ec] = -w, prv[ec] = head[v], head[v] = ec++;
}

int lv[MAXN], q[MAXN], rec[MAXN], parE[MAXN];
bool mark[MAXN];
pii spfa(int source, int sink) {
	memset(lv, 63, sizeof(lv));
	memset(parE, -1, sizeof(parE));
	memset(rec, 0, sizeof(rec));
	memset(mark, 0, sizeof(mark));
	int h = 0, t = 0;
	lv[source] = 0;
	rec[source] = 1e9;
	q[t++] = source;
	mark[source] = true;
	while (t^h){
		int v = q[h++];
		if (h == MAXN) h = 0;
		mark[v] = false;
		for (int e = head[v]; ~e; e = prv[e])
			if (cap[e] && lv[v] + ww[e] < lv[to[e]]){
				lv[to[e]] = lv[v] + ww[e];
				parE[to[e]] = e;
				rec[to[e]] = min(cap[e], rec[v]);
				if (!mark[to[e]]){
					q[t++] = to[e];
					if (t == MAXN) t = 0;
					mark[to[e]] = true;
				}
			}
	}
	if (lv[sink] > 1e8) return {0, 0};
	int v = sink;
	int totW = 0;
	while (~parE[v]){
		int e = parE[v];
		cap[e] -= rec[sink];
		cap[e^1] += rec[sink];
		totW += ww[e] * rec[sink];
		v = from[e];
	}
	return {rec[sink], totW};
}

pii getMCMF(int source, int sink){
	pii ret(0, 0), x;
	while (true){
		x = spfa(source, sink);
		if (!x.F) break;
		ret.F += x.F;
		ret.S += x.S;
	}
	return ret;
}

int lst[MAXVAL], lst2[10];
int main(){
	memset(lst, -1, sizeof(lst));
	memset(lst2, -1, sizeof(lst2));
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(head, -1, sizeof(head));
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> a[i];
	int source = n<<1, sink = n<<1^1;
	int cur = n+1<<1; cur += 2;
	
	for (int i = n-1; ~i; i--){
		if (~lst[a[i]+1]){
			addEdge(i<<1^1, cur+lst[a[i]+1], 1, 0);
			addEdge(cur+i, cur+lst[a[i]+1], INF, 0);
		}
		if (~lst[a[i]-1]){
			addEdge(i<<1^1, cur+lst[a[i]-1], 1, 0);
			addEdge(cur+i, cur+lst[a[i]-1], INF, 0);
		}
		addEdge(cur+i, i<<1, 1, 0);
		lst[a[i]] = i;

		if (~lst2[a[i]%7]){
			addEdge(i<<1^1, cur+n+lst2[a[i]%7], 1, 0);
			addEdge(cur+n+i, cur+n+lst2[a[i]%7], INF, 0);
		}
		addEdge(cur+n+i, i<<1, 1, 0);
		lst2[a[i]%7] = i;
	}

	for (int i = 0; i < n; i++) addEdge(source, i<<1, 1, 0);
	for (int i = 0; i < n; i++) addEdge(i<<1^1, sink, 1, 0);
	for (int i = 0; i < n; i++) addEdge(i<<1, i<<1^1, 1, -1);
	int ts = n+1<<1;
	addEdge(ts, source, 4, 0);
	cout << -getMCMF(ts, sink).S << endl;
	return 0;
}