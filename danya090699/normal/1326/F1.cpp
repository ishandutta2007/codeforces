#include <bits/stdc++.h>
using namespace std;
const int sz=15;
int n, sm[sz][sz], us[sz], f[sz];
vector <int> sp;
long long an[1<<sz];
void dfs()
{
    if(sp.size()==n/2)
    {
        //cout<<1;
        vector <int> sp2;
        int q1=n/2-1, q2=n-n/2-1, l[1<<q1][n], r[1<<q2][n];
        for(int a=0; a<n; a++)
        {
            if(!us[a]) sp2.push_back(a);

            for(int mask=0; mask<(1<<q1); mask++) l[mask][a]=0;
            for(int mask=0; mask<(1<<q2); mask++) r[mask][a]=0;
        }
        for(int a=0; a<f[q1+1]; a++)
        {
            int mask=0;
            for(int i=0; i<q1; i++) mask+=(sm[sp[i]][sp[i+1]]<<i);
            l[mask][sp.back()]++;
            next_permutation(sp.begin(), sp.end());
        }
        for(int a=0; a<f[q2+1]; a++)
        {
            int mask=0;
            for(int i=0; i<q2; i++) mask+=(sm[sp2[i]][sp2[i+1]]<<i);
            r[mask][sp2[0]]++;
            next_permutation(sp2.begin(), sp2.end());
        }
        //cout<<1;
        for(int x=0; x<n; x++)
        {
            for(int y=0; y<n; y++)
            {
                if(us[x] and !us[y])
                {
                    for(int mask=0; mask<(1<<q1); mask++)
                    {
                        for(int mask2=0; mask2<(1<<q2); mask2++)
                        {
                            //cout<<mask+(sm[x][y]<<q1)+(mask2<<(q1+1))<<"\n";
                            an[mask+(sm[x][y]<<q1)+(mask2<<(q1+1))]+=l[mask][x]*r[mask2][y];
                        }
                    }
                }
            }
        }
        //cout<<1;
    }
    else
    {
        int pr=sp.size() ? sp.back() : -1;
        for(int a=pr+1; a<n and sp.size()+(n-a)>=n/2; a++)
        {
            sp.push_back(a), us[a]=1;
            dfs();
            sp.pop_back(), us[a]=0;
        }
    }
}
main()
{
    f[0]=1;
    for(int a=1; a<sz; a++) f[a]=f[a-1]*a;
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<n; b++)
        {
            char sy;
            cin>>sy;
            sm[a][b]=sy-'0';
        }
    }
    dfs();
    for(int a=0; a<(1<<(n-1)); a++) cout<<an[a]<<" ";
}