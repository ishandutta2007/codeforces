#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    char fi[n][m+1];
    int ma[n][m];
    for(int a=0; a<n; a++)
    {
        scanf("%s", fi[a]);
        ma[a][m-1]=1;
        for(int b=m-2; b>=0; b--)
        {
            ma[a][b]=(fi[a][b]==fi[a][b+1]) ? ma[a][b+1]+1 : 1;
        }
    }
    int an=0;
    for(int a=0; a<m; a++)
    {
        vector <vector <int> > pref, suf;
        int yk=0;
        while(yk<n)
        {
            int st=yk;
            while(yk<n and fi[yk][a]==fi[st][a]) yk++;
            pref.resize(pref.size()+1);
            suf.resize(suf.size()+1);
            pref.back().push_back(ma[st][a]);
            for(int b=st+1; b<yk; b++)
            {
                pref.back().push_back(min(pref.back().back(), ma[b][a]));
            }
            suf.back().push_back(ma[yk-1][a]);
            for(int b=yk-2; b>=st; b--)
            {
                suf.back().push_back(min(suf.back().back(), ma[b][a]));
            }
        }
        for(int b=1; b+1<pref.size(); b++)
        {
            int q=pref[b].size()-1, add=pref[b].back();
            if(q<suf[b-1].size() and q<pref[b+1].size())
            {
                add=min(add, min(suf[b-1][q], pref[b+1][q]));
                an+=add;
            }
        }
    }
    cout<<an;
}