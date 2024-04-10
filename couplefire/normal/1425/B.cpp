#include <bits/stdc++.h>
using namespace std;
 
#define MOD 1000000007
 
map<int,int> cycles;
typedef long long ll;
 
vector<int> a;
 
int dp[2100][4100][2], lastCycle;
 
int solve(int pos, int diff, int mustTake) {
 
 
	//if(diff > 2050) return 0; 
 
	// if mustTake is 1, then the required diff is lastCycle - 1 (or 0 if ends in 0)
	// else if mustTake is 0, must be less than lastCycle
	if(pos == a.size()) { 
		if(mustTake) return diff == max(0, lastCycle-1);
		else return diff < lastCycle - 1;
 
	}
 
	int &sum = dp[pos][diff][mustTake];
	if(sum != -1) return sum;
	sum = 0;
 
	// make blue, make red
	sum += solve(pos+1, diff+a[pos], mustTake);
	sum += solve(pos+1, abs(diff-a[pos]), mustTake);
	sum%=MOD;
 
	// dont take this cycle
	if(mustTake == 0) {
		sum += solve(pos+1, diff, mustTake);
		sum%=MOD;
	}
 
	return sum;
 
}
 
int solveAtStop(int cycleSize, int mustTake) {
 
	memset(dp, -1, sizeof(dp));
 
	a.clear();
 
	cycles[cycleSize]--;
	for(auto it=cycles.begin(); it!=cycles.end(); it++) {
		for(int temp=0;temp<it->second;temp++)
			a.push_back(it->first);
	}
	cycles[cycleSize]++;
	lastCycle = cycleSize;
 
	int ans = 0;
	if(mustTake == 0) {
		ans += solve(0, 0, 0);
	}
	ans += solve(0, 0, 1);
	return ans%MOD;
 
}
 
int main() {
 
	int n,m;
	cin>>n>>m;
	vector<vector<int>> adj(n+1);
	int temp;
	for(temp=0;temp<m;temp++) {
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
 
	
	bool visited[n+1]; memset(visited,0, sizeof(visited));
	for(auto nxt : adj[1]) {
 
		if(visited[nxt]) continue;
 
		int cycleSize = 1;
		int cur = nxt, prev = 1;
 
		// special case if loop
		if(adj[cur][0] == adj[cur][1]) {
			visited[cur] = true;
			cycles[2]++;
			continue;
		}
 
		while(cur != 1) {
 
			//cout<<prev<<" "<<cur<<"\n";
			if(cur==-1 || prev==-1) return 0;
			visited[cur] = true;
			
			int nxtNode = -1;
			for(auto lol : adj[cur])
				if(lol != prev)
					nxtNode = lol;
 
			prev = cur;
			cur = nxtNode;
			cycleSize++;
 
		}
 
		cycles[cycleSize]++;
	}
 
	ll ans = 0;
	for(auto it = cycles.begin(); it!= cycles.end(); it++) {
		ans += 2ll*it->second*solveAtStop(it->first, 0);
		//cout<<ans<<"\n";
	}
	
	// special case ends in checkpoint 1. Must take all cycles for this case
	memset(dp, -1, sizeof(dp));
	ans += solveAtStop(0, 1);
 
 
	cout<<ans%MOD<<"\n";
}