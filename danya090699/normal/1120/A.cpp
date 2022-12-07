#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
vector <int> sp[sz];
int q[sz];
void error()
{
    cout<<-1;
    exit(0);
}
main()
{
    //freopen("input.txt", "r", stdin);
    int m, k, n, s;
    cin>>m>>k>>n>>s;
    int ar[m];
    for(int a=0; a<m; a++)
    {
        scanf("%d", &ar[a]);
        sp[ar[a]].push_back(a);
    }
    for(int a=0; a<s; a++)
    {
        int x;
        scanf("%d", &x);
        q[x]++;
    }
    int r=0;
    for(int a=0; a<sz; a++)
    {
        if(q[a])
        {
            if(sp[a].size()<q[a]) error();
            reverse(sp[a].begin(), sp[a].end());
            for(int b=0; b<q[a]-1; b++) sp[a].pop_back();
            r=max(r, sp[a].back()+1);
        }
        else sp[a].clear();
    }
    for(int a=0; a+k<=m; a++)
    {
        int rg=max(r, a+k);
        if(a/k+1+(m-rg)/k>=n)
        {
            vector <int> sp;
            for(int b=0; b<a%k; b++) sp.push_back(b);
            int del=(rg-a)-k;
            for(int b=a; b<rg; b++)
            {
                int x=ar[b];
                if(q[x]<=0 and del) sp.push_back(b), del--;
                q[x]--;
            }
            cout<<sp.size()<<"\n";
            for(int b=0; b<sp.size(); b++) printf("%d ", sp[b]+1);
            return 0;
        }

        int x=ar[a];
        if(sp[x].size())
        {
            sp[x].pop_back();
            if(sp[x].size()) r=max(r, sp[x].back()+1);
            else error();
        }
    }
    error();
}