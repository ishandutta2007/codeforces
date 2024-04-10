#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

int n, m;
int size;
int last = 0;

struct op {
	int o;
	int x, y;
};

op opt[maxn];
string ans;

//map <pair <int, int>, int > s;
unordered_map <long long, bool> s;
unordered_map <long long, int> se;

vector <pair <int, int> > vec, vecb;

vector <int> e[maxn];
int vis[maxn];

struct unionset{
	int fa[maxn];
	
	int find(int x){
		if(fa[x] != x){
			fa[x] = find(fa[x]);
		}
		return fa[x];
	}
	
	int join(int x, int y){
		if(find(x) != find(y)){
			fa[find(x)] = find(y);
		}
		return 0;
	}
	
	int init(){
		for(int i=1;i<=n;i++)fa[i] = i;
		return 0;
	}
} u;

long long getn(int x, int y){
	return 1000000ll * x + y;
}

int dfs(int x, int t, int v){
	if(x == t)return true;
	
	vis[x] = v;
	
	for(int y : e[x]){
		if(vis[y] == v)continue;
		if(!se[getn(min(x, y), max(x, y))])continue;
		if(dfs(y, t, v))return true;
	}
	return false;
}

int solve(int l, int r){
	int i, j;
	int x, y;
	bool flag = false;
	s.clear();
	
	for(i=l;i<=r;i++){
		if(opt[i].o == 2)continue;
		s[getn(min(opt[i].x, opt[i].y),max(opt[i].x, opt[i].y))] = true;
		s[getn(min(opt[i].x % n + 1, opt[i].y % n + 1), max(opt[i].x % n + 1, opt[i].y % n + 1))] = true;
	}
	
	u.init();
	
	sort(vec.begin(), vec.end());
	vecb.clear();
	
	for(i=0;i<vec.size();i+=j){
		for(j=0;i+j<vec.size();j++){
			if(vec[i] != vec[i + j])break;
		}
		if((j & 1)){
			if(!s[getn(vec[i].first, vec[i].second)]){
				u.join(vec[i].first, vec[i].second);
			}
			else vecb.push_back(vec[i]);
		}
	}
	
	for(i=1;i<=n;i++){
		e[i].clear();
	}
	
	s.clear();
	se.clear();
	
	for(auto edge : vecb){
		s[getn(edge.first, edge.second)] = true;
		e[u.find(edge.first)].push_back(u.find(edge.second));
		e[u.find(edge.second)].push_back(u.find(edge.first));
		se[getn(min(u.find(edge.first), u.find(edge.second)), max(u.find(edge.first), u.find(edge.second)))]++;
	}
	
	for(i=l;i<=r;i++){
		opt[i].x = (opt[i].x + last - 1) % n + 1;
		opt[i].y = (opt[i].y + last - 1) % n + 1;
		if(opt[i].x > opt[i].y)swap(opt[i].x, opt[i].y);
		if(opt[i].o == 1){
			vec.push_back(make_pair(opt[i].x, opt[i].y));
			if(!s.count(getn(opt[i].x, opt[i].y))){
				e[u.find(opt[i].x)].push_back(u.find(opt[i].y));
				e[u.find(opt[i].y)].push_back(u.find(opt[i].x));
				s[getn(opt[i].x, opt[i].y)] = true;
				se[getn(min(u.find(opt[i].x), u.find(opt[i].y)), max(u.find(opt[i].x), u.find(opt[i].y)))]++;
			}else{
				if(s[getn(opt[i].x, opt[i].y)]){
					se[getn(min(u.find(opt[i].x), u.find(opt[i].y)), max(u.find(opt[i].x), u.find(opt[i].y)))]--;
				}else{
					se[getn(min(u.find(opt[i].x), u.find(opt[i].y)), max(u.find(opt[i].x), u.find(opt[i].y)))]++;
				}
				s[getn(opt[i].x, opt[i].y)] = !s[getn(opt[i].x, opt[i].y)];
			}
		}else{
			if(dfs(u.find(opt[i].x), u.find(opt[i].y), i)){
				ans.push_back('1');
				last = 1;
			}else{
				ans.push_back('0');
				last = 0;
			}
		}
	}
	
	return 0;
}

int main(){
	int i, j;
	int x, y;
	
	scanf("%d%d", &n, &m);
	
	size = sqrt(m) + 0.5;
	
	size *= 20;
	
	for(i=1;i<=m;i++){
		scanf("%d%d%d", &opt[i].o, &opt[i].x, &opt[i].y);
	}
	
	for(i=1;i<=m;i+=size){
		solve(i, min(i + size - 1, m));
	}
	
	printf("%s\n", ans.c_str());
	
	return 0;
}