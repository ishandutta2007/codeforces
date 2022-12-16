#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

struct pt{
	int x, y, l, r;
	pt() {}
	pt(int a, int b):x(a), y(b) {}
	pt(int a, int b, int c, int d):x(a), y(b), l(c), r(d) {}
	bool operator < (const pt& o) const
	{
		return (l+r) > (o.l+o.r);
	}
};

int g[2010][2010];
int dstl[2010][2010];
int dstr[2010][2010];
int N, M;

stack<pt> neigh;
inline bool is_good(pt p)
{
	return (p.x > 0 && p.y > 0 && p.x <= N && p.y <= M && !g[p.x][p.y] && dstl[p.x][p.y]+dstr[p.x][p.y] > p.l + p.r);
}
void get_neigh(pt p)
{
	pt p1 = pt(p.x+1, p.y, p.l, p.r);
	pt p2 = pt(p.x-1, p.y, p.l, p.r);
	pt p3 = pt(p.x, p.y+1, p.l, p.r+1);
	pt p4 = pt(p.x, p.y-1, p.l+1, p.r);
	if(is_good(p1)) neigh.push(p1);
	if(is_good(p2)) neigh.push(p2);
	if(is_good(p3)) neigh.push(p3);
	if(is_good(p4)) neigh.push(p4);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	memset(dstl, 0x3f3f3f3f, sizeof dstl);
	memset(dstr, 0x3f3f3f3f, sizeof dstr);
	cin >> N >> M;
	int r, c;
	cin >> r >> c;
	int x, y;
	cin >> x >> y;
	for(int i=1;i<=N;++i)
	{
		string s;
		cin >> s;
		for(int j=1;j<=M;++j) {
			if(s[j-1] == '*') g[i][j] = 1;
			//cerr << g[i][j];
		}
		//cerr << endl;
	}
	priority_queue<pt> pq;
	pq.push(pt(r, c, 0, 0));
	dstl[r][c] = 0;
	dstr[r][c] = 0;
	while(!pq.empty())
	{
		pt u = pq.top(); pq.pop();
		if(dstl[u.x][u.y] > u.l) {
			continue;
		}
		//cerr << "  " << u.x << " " << u.y << ": " << u.l << " " << u.r << "  " << g[u.x][u.y] << endl;
		dstl[u.x][u.y] = u.l;
		dstr[u.x][u.y] = u.r;
		get_neigh(u);
		while(!neigh.empty())
		{
			pt p = neigh.top(); neigh.pop();
			pq.push(p);
			dstl[p.x][p.y] = p.l;
			dstr[p.x][p.y] = p.r;
		}
	}
	int ans = 0;
	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=M;++j)
		{
			if(dstl[i][j] <= x && dstr[i][j] <= y)
			{
				++ans;
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}