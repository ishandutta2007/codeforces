#include<bits/stdc++.h>
using namespace std;

const int maxn = 100100;
vector<int> s;
vector<int> v[maxn];
int n, ans[maxn];
struct node{
	int a, t, x, id, ans;
}q[maxn];
bool cmp(const int &a, const int &b){
	return q[a].t < q[b].t;
}

int c[maxn], tag[maxn], inx;
void add(int x, int v){
	for(; x <= n; x += x & -x)
		if(tag[x] == inx) c[x] += v;
		else c[x] = v, tag[x] = inx;
}
int ask(int x){
	int ans = 0;
	for(; x; x -= x & -x)
		if(tag[x] == inx) ans += c[x];
	return ans;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &q[i].a, &q[i].t, &q[i].x);
		q[i].id = i;
		s.push_back(q[i].x);
	}
	sort(s.begin(), s.end());
	s.resize(unique(s.begin(), s.end()) - s.begin());
	for(int i = 1; i <= n; i++)
		v[lower_bound(s.begin(), s.end(), q[i].x) - s.begin()].push_back(i);
	for(int i = 0; i < (int)s.size(); i++){
		inx++;
		sort(v[i].begin(), v[i].end(), cmp);
		for(auto t : v[i])
			if(q[t].a == 1) add(q[t].id, 1);
			else if(q[t].a == 2) add(q[t].id, -1);
			else ans[q[t].id] = ask(q[t].id);
	}
	for(int i = 1; i <= n; i++)
		if(q[i].a == 3) printf("%d\n", ans[i]);
	return 0;
}