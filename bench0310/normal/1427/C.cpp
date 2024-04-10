#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r,n;
    cin >> r >> n;
    vector<array<int,3>> v(n+1);
    v[0]={0,1,1};
    for(int i=1;i<=n;i++) for(int j=0;j<3;j++) cin >> v[i][j];
    auto mv=[&](int i,int j)->bool
    {
        auto [ta,xa,ya]=v[i];
        auto [tb,xb,yb]=v[j];
        return (abs(xa-xb)+abs(ya-yb)<=tb-ta);
    };
    vector<int> res(n+1,-n);
    res[0]=0;
    vector<int> best(n+1,0);
    auto chmax=[&](int &a,int b){a=max(a,b);};
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(v[i][0]-v[j][0]>=2*r-2)
            {
                chmax(res[i],best[j]+1);
                break;
            }
            if(mv(j,i)) chmax(res[i],res[j]+1);
        }
        best[i]=max(best[i-1],res[i]);
    }
    cout << best[n] << "\n";
    return 0;
}