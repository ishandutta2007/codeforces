#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    char fi[n][m];
    for(int a=0; a<n; a++) for(int b=0; b<m; b++) cin>>fi[a][b];
    vector <pair <int, int> > an;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++)
        {
            if(fi[a][b]=='1')
            {
                bool fo=0;
                for(int i=0; i<2; i++)
                {
                    for(int j=0; j<2; j++)
                    {
                        int lx=a-i, ly=b-j, ok=1;
                        for(int c=lx; c<=lx+1; c++)
                        {
                            for(int d=ly; d<=ly+1; d++)
                            {
                                if(!(c>=0 and c<n and d>=0 and d<m and fi[c][d]=='1')) ok=0;
                            }
                        }
                        if(ok)
                        {
                            an.push_back({lx+1, ly+1});
                            fo=1;
                            break;
                        }
                    }
                    if(fo) break;
                }
                if(fo==0)
                {
                    cout<<-1;
                    return 0;
                }
            }
        }
    }
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) cout<<an[a].first<<" "<<an[a].second<<"\n";
}