#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> v(2*n);
    for(int i=0;i<2*n;i++) cin >> v[i];
    sort(v.begin(),v.end());
    int res=(1<<30);
    for(int i=0;i<2*n;i++)
    {
        for(int j=i+1;j<2*n;j++)
        {
            vector<int> a;
            for(int k=0;k<2*n;k++) if(k!=i&&k!=j) a.push_back(v[k]);
            int x=a[1]-a[0];
            for(int k=3;k<(int)a.size();k+=2) x+=(a[k]-a[k-1]);
            res=min(res,x);
        }
    }
    cout << res << "\n";
    return 0;
}