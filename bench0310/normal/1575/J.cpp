#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    set<array<int,2>> s[m+1]; //r,a
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int a;
            cin >> a;
            if(a!=2) s[j].insert({i,a});
        }
    }
    while(k--)
    {
        int c;
        cin >> c;
        int r=1;
        while(1)
        {
            auto it=s[c].lower_bound({r,0});
            if(it==s[c].end())
            {
                cout << c << " ";
                break;
            }
            auto [nr,a]=(*it);
            s[c].erase(it);
            r=nr;
            if(a==1) c++;
            else c--;
        }
    }
    cout << "\n";
    return 0;
}