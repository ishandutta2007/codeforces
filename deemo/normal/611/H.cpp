#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cassert>

using namespace std;

#define FAILURE {cout << "-1\n"; return 0;}

const int BIGENOUGH = 1e6 + 3;
const int MAXN = 2e5 + 100;
const int MAXSZ = 6 + 3;
const int SS = 50 + 5;

int n, sz, ecount[MAXSZ][MAXSZ], size[MAXSZ], mn[MAXSZ], mx[MAXSZ], ptr[MAXSZ], tt;
int head[SS], thead[SS], prv[MAXN], from[MAXN], to[MAXN], cap[MAXN], p[SS], ec;
int q[SS], lv[SS];
pair<int, int>	ed[MAXN];
vector<vector<int>>	vec;
vector<int>	gec;
bool pic[SS];

int dcount(int x){
	int ret = 0;
	while (x){
		ret++;
		x/=10;
	}
	return	ret;
}

void add_edge(int u, int v, int uv, int vu = 0){
	from[ec] = u, to[ec] = v, cap[ec] = uv, prv[ec] = head[u];	head[u] = ec++;
	from[ec] = v, to[ec] = u, cap[ec] = vu, prv[ec] = head[v];	head[v] = ec++;
}

bool bfs(int v, int des){
	memset(lv, 63, sizeof(lv));
	lv[v] = 0;
	int h = 0, t = 0;
	q[t++] = v;
	while (h < t){
		v = q[h++];
		for (int e = head[v]; e != -1; e = prv[e])
			if (cap[e] && lv[to[e]] > lv[v] + 1){
				lv[to[e]] = lv[v] + 1;
				q[t++] = to[e];
			}
	}
	return	lv[des] < BIGENOUGH;
}

int dfs(int v, int sink, int flow = BIGENOUGH){
	if (v == sink || flow == 0)	return	flow;
	int ret = 0;
	for (; p[v] != -1; p[v] = prv[p[v]])
		if (lv[v] + 1 == lv[to[p[v]]]){
			int ran = dfs(to[p[v]], sink, min(flow, cap[p[v]]));
			flow -= ran;
			ret += ran;
			cap[p[v]] -= ran;
			cap[p[v]^1] += ran;
			if (flow == 0)	break;
		}
	return	ret;
}

int max_flow(int source, int sink){
	for (int e = 0; e < ec; e += 2)
		cap[e] = cap[e] + cap[e^1], cap[e^1] = 0;
	int ret = 0;
	while (bfs(source, sink)){
		memcpy(p, head, sizeof(head));
		ret += dfs(source, sink);
	}
	return	ret;
}

void gen(int cur = 1){
	if (cur == sz){
		vec.push_back(gec);
		return;
	}

	for (int i = 1; i <= sz; i++)
		if (!pic[i]){
			pic[i] = 1;
			for (int j = 1; j <= sz; j++)
				if (j != i && pic[j] && ecount[min(i, j)][max(i, j)]){
					gec[i - 1] = j;
					gen(cur + 1);
				}
			pic[i] = 0;
		}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	sz = dcount(n);
	//bool flag = n == 1000;
	for (int i = 0; i < n - 1; i++){
		string a, b;	cin >> a >> b;
	//	if ((i == 0 || i == 1) && a.size() != 3)	flag = 0;
	//	if ((i == 0 || i == 1) && b.size() != 3)	flag = 0;
		if (a.size() < b.size())	
			ecount[(int)a.size()][(int)b.size()]++;
		else
			ecount[(int)b.size()][(int)a.size()]++;
	}
	for (int i = 1, j = 1; i <= sz; j *= 10, i++)	mn[i] = j, ptr[i] = j, mx[i] = min(n, 10 * j - 1), size[i] = mx[i] - mn[i] + 1;
	for (int i = 1; i <= sz; i++)	
		if (size[i] - 1 < ecount[i][i])	FAILURE
	for (int i = 1; i <= sz; i++)	
		for (int j = 0; j < ecount[i][i]; j++)	ed[tt++] = {mn[i], ++ptr[i]};

	//running flow
	memset(head, -1, sizeof(head));
	int source = 50, sink = 51;
	int exp = 0;
	for (int i = 1; i <= sz; i++)
		add_edge(i, sink, size[i] - (ptr[i] - mn[i]) - 1);
	int fl = 0, tc = ec;
	gec.resize(sz);	gec[0] = -1, pic[1] = 1;
	memcpy(thead, head, sizeof(head));
	gen();
	for (int i = 0; i < (int)vec.size(); i++){
		//if (flag)	cout << i << endl;
		for (int j = 1; j < sz; j++)
			ecount[min(j + 1, vec[i][j])][max(j + 1, vec[i][j])]--;
		
		ec = tc;
		memcpy(head, thead, sizeof(thead));
		for (int i = 1; i <= sz; i++)
			for (int j = i + 1; j <= sz; j++)
				add_edge(source, i * sz + j, ecount[i][j]), add_edge(i * sz + j, i, ecount[i][j]), add_edge(i * sz + j, j, ecount[i][j]);
		if (max_flow(source, sink) == n - 1 - tt - (sz - 1)){
			fl = i + 1;
			break;
		}
		for (int j = 1; j < sz; j++)
			ecount[min(j + 1, vec[i][j])][max(j + 1, vec[i][j])]++;
	}
	if (fl == 0)	FAILURE
	
	for (int i = 1; i <= sz; i++)
		for (int j = i + 1; j <= sz; j++)
			for (int e = 0; e < ec; e++)
				if (from[e] == i && to[e] == i * sz + j)
					for (int w = 0; w < cap[e]; w++){
						if (ptr[i] < mx[i])
							ed[tt++] = {++ptr[i], mn[j]};
						else
							ed[tt++] = {mn[i], mn[j]};
						ecount[i][j]--;
					}
				else if (from[e] == j && to[e] == i * sz + j)
					for (int w = 0; w < cap[e]; w++){
						if (ptr[j] < mx[j])
							ed[tt++] = {++ptr[j], mn[i]};
						else
							ed[tt++] = {mn[j], mn[i]};
						ecount[i][j]--;
					}
	for (int i = 1; i < sz; i++)
		ed[tt++] = {mn[i + 1], mn[vec[fl - 1][i]]};

	for (int v = 0; v < tt; v++)
		cout << ed[v].first << " " << ed[v].second << "\n";
	return	0;
}