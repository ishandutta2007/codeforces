#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, t;
    cin>>n>>t;
    pair <pair <int, int>, int> ar[n];
    bool us[n];
    for(int a=0; a<n; a++)
    {
        ar[a].second=a+1;
        scanf("%d%d", &ar[a].first.second, &ar[a].first.first);
        us[a]=0;
    }
    sort(ar, ar+n);
    vector <int> sp[n+1];
    for(int a=0; a<n; a++)
    {
        sp[ar[a].first.second].push_back(a);
    }
    int yk=0, q=0, an=0;
    long long su=0;
    for(int a=0; a<=n; a++)
    {
        while(q<a and yk<n)
        {
            if(us[yk]==0)
            {
                su+=ar[yk].first.first, q++;
            }
            yk++;
        }
        if(q==a and su<=t) an=a;
        for(int b=0; b<sp[a].size(); b++)
        {
            int p=sp[a][b];
            if(p<yk)
            {
                su-=ar[p].first.first, q--;
            }
            else us[p]=1;
        }
    }
    q=an, yk=0;
    cout<<an<<"\n"<<an<<"\n";
    while(q)
    {
        if(ar[yk].first.second>=an)
        {
            cout<<ar[yk].second<<" ";
            q--;
        }
        yk++;
    }
}