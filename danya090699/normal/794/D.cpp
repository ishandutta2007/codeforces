#include <bits/stdc++.h>
#define iter set <int, int>::iterator
using namespace std;
struct el
{
    int nu=-1;
    map <int, int> ne;
};
el nel;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, cq=0;
    cin>>n>>m;
    vector <int> sv[n];
    vector <el> bor(1);
    int cnu[n];
    for(int a=0; a<n; a++) sv[a].push_back(a);
    for(int a=0; a<m; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v), sv[v].push_back(u);
    }
    for(int a=0; a<n; a++)
    {
        sort(sv[a].begin(), sv[a].end());
        int cu=0;
        for(int b=0; b<sv[a].size(); b++)
        {
            int next=sv[a][b];
            if(bor[cu].ne.find(next)==bor[cu].ne.end())
            {
                bor[cu].ne[next]=bor.size();
                bor.push_back(nel);
            }
            cu=bor[cu].ne[next];
        }
        if(bor[cu].nu==-1)
        {
            bor[cu].nu=cq, cq++;
        }
        cnu[a]=bor[cu].nu;
    }
    int nu[cq];
    set <int> csv[cq];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<sv[a].size(); b++)
        {
            int ne=sv[a][b];
            int c1=cnu[a], c2=cnu[ne];
            if(c1!=c2)
            {
                csv[c1].insert(c2);
                csv[c2].insert(c1);
            }
        }
    }
    bool pos=1;
    if(cq==1) nu[0]=1;
    else
    {
        int cu=-1, pr=-1;
        for(int a=0; a<cq; a++)
        {
            if(csv[a].size()==1) cu=a;
            else if(csv[a].size()!=2)
            {
                pos=0;
                break;
            }
        }
        if(cu==-1) pos=0;
        if(pos)
        {
            for(int a=0; a<cq; a++)
            {
                nu[cu]=a+1;
                for(iter it=csv[cu].begin(); it!=csv[cu].end(); it++)
                {
                    int ne=*it;
                    if(ne!=pr)
                    {
                        pr=cu, cu=ne;
                        break;
                    }
                }
            }
        }
    }
    if(pos)
    {
        cout<<"YES\n";
        for(int a=0; a<n; a++) printf("%d ", nu[cnu[a]]);
    }
    else cout<<"NO";
}