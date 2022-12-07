#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, n2, m2;
    cin>>n>>m>>n2>>m2;
    int f, x, y, z;
    cin>>f>>x>>y>>z;
    int fi[n][m], be[n][m-m2+1];
    for(int a=0; a<n; a++)
    {
        deque <pair <int, int> > se;
        for(int b=0; b<m; b++)
        {
            fi[a][b]=f;
            while(se.size() and se.back()>make_pair(f, b)) se.pop_back();
            se.push_back({f, b});
            if(se.front().second<=b-m2) se.pop_front();
            if(b+1>=m2)
            {
                be[a][b+1-m2]=se.front().first;
            }
            f=(f*x+y)%z;
        }
    }
    int an=0;
    for(int a=0; a<=m-m2; a++)
    {
        deque <pair <int, int> > se;
        for(int b=0; b<n; b++)
        {
            while(se.size() and se.back()>make_pair(be[b][a], b)) se.pop_back();
            se.push_back({be[b][a], b});
            if(se.front().second<=b-n2) se.pop_front();
            if(b+1>=n2) an+=se.front().first;
        }
    }
    cout<<an;
}