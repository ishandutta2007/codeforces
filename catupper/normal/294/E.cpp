#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
typedef pair<long long, long long> P;

vector<P> edge[5250];
long long s[5250], u[5250];
long long ans = 1LL << 60;
bool used[5250];
long long size(long long x, long long last){
    long long &res = s[x];
    res = 1;
    for(long long i = 0;i < edge[x].size();i++){
	long long to = edge[x][i].first;
	if(to == last)continue;
	res += size(to, x);
    }
    return res;
}

long long center(long long x,long long last){
    long long n = x;
    while(true){
	long long change = 0;
	for(long long i = 0;i < edge[n].size();i++){
	    long long to = edge[n][i].first;
	    if(to == last)continue;
	    if(s[to] * 2 > s[x]){
		last = n;
		n = to;
		change = 1;
		break;
	    }
	}
	if(!change)break;
    }
    return n;
}

long long solve(long long x, long long last = -1){
    long long res = 0;
    long long &tmp = s[x];
    long long &und = u[x];
    tmp = 1;
    und = 0;
    for(long long i = 0;i < edge[x].size();i++){
	long long to = edge[x][i].first, cost = edge[x][i].second;
	if(to == last || (used[x] && used[to]))continue;
	res += solve(to, x);
	res += tmp * u[to] + s[to] * und + tmp * s[to] * cost;
	und += u[to] + s[to] * cost;
	tmp += s[to];
    }
    return res;
}

long long dfs(long long x, long long last = -1){
    for(long long i = 0;i < edge[x].size();i++){
	long long to = edge[x][i].first, cost = edge[x][i].second;
	if(to == last)continue;
	used[x] = true;
	used[to] = true;
	size(x, to);
	size(to, x);
	long long p = center(x, to);
	long long q = center(to, x);
	if(used[p] && used[q]){
	    used[x] = false;
	    used[to] = false;
	    ans = min(ans, solve(p));
	}
	else{
	    edge[p].push_back(P(q, cost));
	    ans = min(ans, solve(p));
	    edge[p].pop_back();
	}
	used[x] = false;
	used[to] = false;
	dfs(to, x);
    }
}

int main(){
    long long n, a, b, c;
    cin >> n;
    for(long long i = 0;i < n - 1;i++){
	cin >> a >> b >> c;
	edge[a].push_back(P(b,c));
	edge[b].push_back(P(a,c));
    }
    
    dfs(1);
    cout << ans << endl;
    return 0;
}