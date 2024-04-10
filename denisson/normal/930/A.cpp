#include <bits/stdc++.h>
                     
using namespace std;
             
typedef long long ll;
#define mp make_pair    
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
vector<int> g[100007];

int h[100007];

void dfs(int v, int hh){
	h[hh] ^= 1;
	for (int to : g[v]) dfs(to, hh + 1);
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
   	cin >> n;
   	for (int i = 1; i < n; i++){
   		int p;
   		cin >> p;
   		p--;
   		g[p].pb(i);
   	}
   	dfs(0, 0);
   	int ans = 0;
   	for (int i = 0; i < 100007; i++) ans += h[i];
   	cout << ans;
}