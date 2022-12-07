#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m=0;
    cin>>n;
    int ot[n][2], maxi=-1, an[n+1];
    map <int, int> ma;
    for(int a=0; a<n; a++)
    {
        scanf("%lld%lld", &ot[a][0], &ot[a][1]);
        ma[ot[a][0]]=0, ma[ot[a][1]+1]=0;
        maxi=max(maxi, ot[a][1]);
        an[a+1]=0;
    }
    ma[maxi+1]=0;
    vector <int> sp;
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        (*it).second=m, m++;
        sp.push_back((*it).first);
    }
    //cout<<m;
    int add[m];
    for(int a=0; a<m; a++) add[a]=0;
    for(int a=0; a<n; a++)
    {
        add[ma[ot[a][0]]]++, add[ma[ot[a][1]+1]]--;
    }
    int cu=0;
    for(int a=0; a<m-1; a++)
    {
        cu+=add[a], an[cu]+=sp[a+1]-sp[a];
    }
    for(int a=1; a<=n; a++) printf("%lld ", an[a]);
}