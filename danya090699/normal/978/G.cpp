#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int an[n], q[m];
    vector <pair <int, int> > st[n];
    for(int a=0; a<n; a++) an[a]=0;
    for(int a=0; a<m; a++)
    {
        int s, d, c;
        cin>>s>>d>>c;
        s--, d--;
        st[s].push_back(make_pair(d, a));
        q[a]=c;
        an[d]=m+1;
    }
    set <pair <int, int> > se;
    bool ok=1;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<st[a].size(); b++) se.insert(st[a][b]);
        if(an[a]==0)
        {
            if(se.size())
            {
                int nu=(*se.begin()).second, en=(*se.begin()).first;
                se.erase(se.begin());
                q[nu]--, an[a]=nu+1;
                if(q[nu]) se.insert(make_pair(en, nu));
            }
        }
        else
        {
            if(se.size())
            {
                int en=(*se.begin()).first;
                if(en<=a)
                {
                    ok=0;
                    break;
                }
            }
        }
    }
    if(ok)
    {
        for(int a=0; a<n; a++) cout<<an[a]<<" ";
    }
    else cout<<-1;
}