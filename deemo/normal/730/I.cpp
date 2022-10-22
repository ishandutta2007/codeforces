#include<bits/stdc++.h>

using namespace std;

const int MAXN = 3e3 + 10;

#define F first
#define S second

int n, a, b, s[MAXN], p[MAXN], sec[MAXN], gec[MAXN];
bool mark[MAXN];
vector<int>	pvec, svec;

bool cmp(int u, int v){return p[u] > p[v];}
bool cmp2(int u, int v){return p[u] - s[u] > p[v] - s[v];}
bool cmp3(int u, int v){return s[u] > s[v];}

pair<int, int>	get(int ind){
	if (ind + 1 > a + b || ind + 1 < a)	return {-1, -1};
	pvec.clear();
	svec.clear();
	memset(mark, 0, sizeof(mark));
	int ret = p[sec[ind]];
	pvec.push_back(sec[ind]);
	mark[sec[ind]] = 1;
	copy(sec, sec + ind, gec);
	sort(gec, gec + ind, cmp2);
	for (int i = 0; i < a - 1; i++)
		ret += p[gec[i]], mark[gec[i]] = 1, pvec.push_back(gec[i]);
	for (int i = a - 1; i < ind; i++)
		ret += s[gec[i]], mark[gec[i]] = 1, svec.push_back(gec[i]);
	int rem = a + b - (ind + 1);
	iota(gec, gec + n, 0);
	sort(gec, gec + n, cmp3);
	for (int i = 0; rem && i < n; i++)
		if (!mark[gec[i]])	
			rem--, ret += s[gec[i]], svec.push_back(gec[i]);
	return {ret, ind};
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> a >> b;
	for (int i = 0; i < n; i++)	cin >> p[i];
	for (int i = 0; i < n; i++)	cin >> s[i];
	iota(sec, sec + n, 0);
	sort(sec, sec + n, cmp);
	pair<int, int>	mx(-1, -1);
	for (int i = 0; i < n; i++)
		mx = max(mx, get(i));
	get(mx.S);
	cout << mx.F << "\n";
	for (int u:pvec)
		cout << u+1 << " ";
	cout << "\n";
	for (int u:svec)
		cout << u+1 << " ";
	cout << "\n";
	return 0;
}