//Come on, make Togliatti great again!
#include <bits/stdc++.h>
#define iter map <int, int>::iterator
using namespace std;
const int sz=1010;
int q=0;
vector <int> bor(1);
vector <map <int, int> > go(1);
vector <vector <int> > sp[sz];
vector <int> sv[sz];
bool us[sz];
void dfs(int v)
{
    us[v]=1, q++;
    for(int a=0; a<sv[v].size(); a++) if(us[sv[v][a]]==0) dfs(sv[v][a]);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, rq=0;
    cin>>n;
    bor[0]=-1;
    for(int a=0; a<n; a++)
    {
        int le=n-1;
        while(le>0)
        {
            rq++;
            vector <int> ve;
            int si;
            char sy;
            if(le<n-1) scanf("%c", &sy);
            scanf("%d", &si);
            scanf("%c", &sy);
            le-=si;
            for(int b=0; b<si; b++)
            {
                if(b!=0) scanf("%c", &sy);
                int x;
                scanf("%d", &x);
                ve.push_back(x-1);
            }
            sort(ve.begin(), ve.end());
            sp[a].push_back(ve);
            int cu=0;
            for(int b=0; b<ve.size(); b++)
            {
                iter it=go[cu].find(ve[b]);
                if(it==go[cu].end())
                {
                    map <int, int> nel;
                    go[cu][ve[b]]=bor.size();
                    bor.push_back(-1);
                    go.push_back(nel);
                }
                cu=go[cu][ve[b]];
            }
            bor[cu]=a;
        }
    }
    if(rq==(n-1)*2)
    {
        for(int a=0; a<n; a++)
        {
            for(int b=0; b<sp[a].size(); b++)
            {

                for(int c=0; c<n; c++) us[c]=1;

                for(int c=0; c<sp[a][b].size(); c++) us[sp[a][b][c]]=0;
                int cu=0;
                for(int c=0; c<n; c++)
                {
                    if(us[c])
                    {
                        if(go[cu].find(c)==go[cu].end())
                        {
                            cu=-1;
                            break;
                        }
                        else cu=go[cu][c];
                    }
                }
                if(cu!=-1)
                {
                    if(bor[cu]!=-1)
                    {
                        sv[a].push_back(bor[cu]);
                    }
                }
            }
        }
        for(int a=0; a<n; a++) us[a]=0;
        dfs(0);
        if(q==n)
        {
            cout<<n-1<<"\n";
            for(int a=0; a<n; a++)
            {
                for(int b=0; b<sv[a].size(); b++)
                {
                    int to=sv[a][b];
                    if(a<to) cout<<a+1<<" "<<to+1<<"\n";
                }
            }
        }
        else cout<<-1;
    }
    else cout<<-1;
}