#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll dp[N][2], a[N];
ll ans = 0;
vector<int> G[N];

void dfs(int cur, int fa, int bit)
{
    ll q = 0;
    int b = (a[cur] >> bit) & 1;//a[x]bit01
    dp[cur][b] = 1;//
    dp[cur][b ^ 1] = 0;//
    /*
    for (int i = 0; i<G[cur].size(); i++){
        int v = G[cur][i];
        if (v == fa)continue;
        dfs(v, cur, bit);
        q += dp[cur][0] * dp[v][1] + dp[cur][1] * dp[v][0];//x1^00^1
        dp[cur][b ^ 0] += dp[v][0];//
        dp[cur][b ^ 1] += dp[v][1];//
    }
    */
    for(auto v:G[cur]){
    //	int v=G[cur][o];
    	if(v!=fa){
    		dfs(v, cur, bit);
        	q += dp[cur][0] * dp[v][1] + dp[cur][1] * dp[v][0];//x1^00^1
        	dp[cur][b ^ 0] += dp[v][0];//
        	dp[cur][b ^ 1] += dp[v][1];//
		}
	}
    ans += (q << bit);//
}
int main()
{
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++){
	    cin >> a[i];
        ans += a[i];
    }
    for (int i = 0; i<n - 1; i++){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    //1e6202^20=1048576 
    for (int i = 0; i <= 20; i++)
        dfs(1, 0, i);
   return 0*printf("%I64d\n",ans);
}
/*
5
1 2 3 4 5
1 2
2 3
3 4
3 5

52
*/