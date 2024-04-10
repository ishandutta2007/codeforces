#include <bits/stdc++.h>
using namespace std;
int *pr;
struct el
{
    int nu;
    bool operator < (const el b) const
    {
        return (pr[nu]<pr[b.nu]);
    }
};
el nel;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n;
    pr=new int[n];
    for(int a=0; a<n; a++) scanf("%d", &pr[a]);
    int co[n][2];
    set <el> se[3];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &co[a][0]);
        co[a][0]--;
        nel.nu=a;
        se[co[a][0]].insert(nel);
    }
    for(int a=0; a<n; a++)
    {
        scanf("%d", &co[a][1]);
        co[a][1]--;
        nel.nu=a;
        se[co[a][1]].insert(nel);
    }
    scanf("%d", &q);
    for(int a=0; a<q; a++)
    {
        int cu;
        scanf("%d", &cu);
        cu--;
        if(se[cu].size()==0) cout<<-1<<" ";
        else
        {
            int nu=(*se[cu].begin()).nu;
            cout<<pr[nu]<<" ";
            int c1=co[nu][0], c2=co[nu][1];
            nel.nu=nu;
            se[c1].erase(nel);
            se[c2].erase(nel);
        }
    }
}