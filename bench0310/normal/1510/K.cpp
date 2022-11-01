#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(2*n+1,0);
    for(int i=1;i<=2*n;i++) cin >> v[i];
    vector<int> ini=v;
    auto one=[&]()
    {
        for(int i=1;i<=2*n;i+=2) swap(v[i],v[i+1]);
    };
    auto two=[&]()
    {
        for(int i=1;i<=n;i++) swap(v[i],v[n+i]);
    };
    auto ok=[&]()->bool
    {
        for(int i=1;i<=2*n;i++) if(v[i]!=i) return 0;
        return 1;
    };
    int res=2*n+1;
    for(int o=0;o<2;o++)
    {
        for(int i=0;i==0||v!=ini;i++)
        {
            if(ok()) res=min(res,i);
            if((o+i)&1) one();
            else two();
        }
    }
    if(res==2*n+1) res=-1;
    cout << res << "\n";
    return 0;
}