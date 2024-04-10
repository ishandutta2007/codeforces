#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
vector<vector<int> > data;
int ans = 0;
struct Inf{int c; int nc; int ne; int nne;};
Inf dfs(int vertex, int last){
    Inf ninf = {0, 0, 0, 0};
    for (int i=0; i < data[vertex].size(); i++){
        int to = data[vertex][i];
        if (to==last) continue;
        Inf g = dfs(to, vertex);
        Inf rg = {g.ne, g.nne + g.ne, g.c, g.c + g.nc};
        //cout << rg.c << " " << rg.nc << " " << rg.ne << " " << rg.nne << endl;
        ans += (rg.nc*ninf.c + ninf.nc*rg.c) / 2;
        ans += (rg.ne*ninf.nne + ninf.ne*rg.nne) / 2;
        int H = (rg.nc*ninf.ne + ninf.nne*rg.c);
        H /= 2;
        H += (ninf.ne * rg.c+1)/2;
        ans += H;
        H = (ninf.nc*rg.ne + rg.nne*ninf.c);
        H /= 2;
        H += (rg.ne * ninf.c+1)/2;
        ans += H;
        //cout << ans << endl;
        ninf.c += rg.c;
        ninf.nc += rg.nc;
        ninf.ne += rg.ne;
        ninf.nne += rg.nne;
    }
    ans += (ninf.nc) / 2;
    ans += (ninf.nne)/2 + ((ninf.ne+1)/2);
    ninf.c++;
    return ninf;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    data.resize(n, {});
    for (int i=0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        data[a-1].push_back(b-1);
        data[b-1].push_back(a-1);
    }
    dfs(0, -1);
    cout << ans;
}