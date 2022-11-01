#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> val(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n+1;i++)
    {
        int id=i%(n+1);
        for(int j=1;j<=n;j++)
        {
            int a;
            cin >> a;
            val[id][a]=(n-j+1);
        }
    }
    vector<array<int,2>> opt(n+1,{0,0});
    set<array<int,2>> s;
    for(int i=1;i<=n;i++)
    {
        s.insert({val[0][i],i});
        auto it=s.rbegin();
        int one=(*it)[1];
        int two=0;
        if(i>1)
        {
            it++;
            two=(*it)[1];
        }
        for(int j=1;j<=n;j++)
        {
            if(one!=j) opt[j]=max(opt[j],{val[j][one],i});
            else if(i>0) opt[j]=max(opt[j],{val[j][two],i});
        }
    }
    for(int i=1;i<=n;i++) cout << opt[i][1] << " \n"[i==n];
    return 0;
}