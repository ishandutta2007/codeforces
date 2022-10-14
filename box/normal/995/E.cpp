
// Problem : CF995E Number Clicker
// Contest : Luogu
// URL : https://www.luogu.com.cn/problem/CF995E
// Memory Limit : 250 MB
// Time Limit : 5000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define fi first
#define se second
#define pb push_back
 
#define ll long long
#define pii pair<int, int>
//#define int ll
int MOD = 1000000007;

int modinv(int i) {
	if(i < 2) return i;
	return 1ll*(MOD-MOD/i)*modinv(MOD%i)%MOD;
}

function<int(int)> fwf[] = {[](int i){return (i+1)-((i==MOD-1)?MOD:0);}, [](int i){return (i-1)+(i==0?MOD:0);}, modinv};
function<int(int)> bwf[] = {[](int i){return (i-1)+(i==0?MOD:0);}, [](int i){return (i+1)-((i==MOD-1)?MOD:0);}, modinv};
map<int, int> fw, bw;
queue<int> BFS;

int uTh = 1000000;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int U, V; cin >> U >> V >> MOD;
    fw[U] = -1; BFS.push(U);
    while(fw.size() < uTh && !BFS.empty()) {
    	int k = BFS.front(), t; BFS.pop();
    	rep(i, 3) {
    		t = fwf[i](k);
    		if(!fw.count(t)) {
    			fw[t] = i;
    			BFS.push(t);
    		}
    	}
    }
    while(!BFS.empty()) BFS.pop();
    bw[V] = -1; BFS.push(V);
    while(bw.size() < uTh && !BFS.empty()) {
    	int k = BFS.front(), t; BFS.pop();
    	rep(i, 3) {
    		t = bwf[i](k);
    		if(!bw.count(t)) {
    			bw[t] = i;
    			BFS.push(t);
    		}
    	}
    }
    int mid = -1, at;
    for(auto& k:fw)
    	if(bw.count(k.fi)) {
    		mid = k.fi;
    		break;
    	}
    assert(mid != -1);
    deque<int> ans; at = mid;
    while(at != U) {
    	int i = fw[at];
    	ans.push_front(i);
    	at = bwf[i](at);
    }
    at = mid;
    while(at != V) {
    	int i = bw[at];
    	ans.push_back(i);
    	at = fwf[i](at);
    }
    cout << ans.size() << endl;
    for(auto& i:ans) cout << i+1 << ' ';
}