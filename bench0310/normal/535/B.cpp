#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    for(int i=1;i<=9;i++)
    {
        for(int j=0;j<(1<<i);j++)
        {
            int x=0;
            for(int k=0;k<i;k++) x=(10*x+((j&(1<<k))>0?4:7));
            v.push_back(x);
        }
    }
    sort(v.begin(),v.end());
    int n;
    cin >> n;
    for(int i=0;i<(int)v.size();i++) if(v[i]==n) cout << i+1 << "\n";
    return 0;
}