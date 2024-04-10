#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    m=(m*8)/n;
    int st=1;
    while(st<n and m) st*=2, m--;
    map <int, int> ma;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        ma[x]++;
    }
    vector <int> pref;
    pref.push_back(0);
    for(auto it=ma.begin(); it!=ma.end(); it++) pref.push_back(pref.back()+(*it).second);
    if(st>=pref.size()-1) cout<<0;
    else
    {
        int an=1e9;
        for(int a=0; a+st<=pref.size()-1; a++)
        {
            int cu=pref.back()-(pref[a+st]-pref[a]);
            an=min(an, cu);
        }
        cout<<an;
    }
}