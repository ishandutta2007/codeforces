#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<array<int,2>> res(n+1,{0,0});
    vector<array<int,2>> opt(n+1,{0,0});
    vector<int> now;
    int lim=(n+k-2)/(k-1);
    for(int i=1;i<=n*k;i++)
    {
        int c;
        cin >> c;
        if(res[c][0]==0)
        {
            if(opt[c][0]==0) opt[c][0]=i;
            else if(opt[c][1]==0)
            {
                opt[c][1]=i;
                now.push_back(c);
            }
        }
        if((int)now.size()==lim||i==n*k)
        {
            for(int a:now) res[a]=opt[a];
            opt.assign(n+1,{0,0});
            now.clear();
        }
    }
    for(int i=1;i<=n;i++) cout << res[i][0] << " " << res[i][1] << "\n";
    return 0;
}