#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int pr[sz], si[sz], ar[sz][3];
bool us[sz];
bool comp(int a, int b){return ar[a][2]>ar[b][2];}
int find_se(int v)
{
    if(pr[v]==v) return v;
    else
    {
        pr[v]=find_se(pr[v]);
        return pr[v];
    }
}
void unite(int v, int v2)
{
    if(v!=v2)
    {
        if(si[v]<si[v2]) swap(v, v2);
        pr[v2]=v, si[v]+=si[v2];
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, an=0;
    cin>>n>>m;
    int p[m];
    for(int a=0; a<n; a++)
    {
        pr[a]=a, si[a]=1, us[a]=0;
    }
    for(int a=0; a<m; a++)
    {
        p[a]=a;
        for(int b=0; b<3; b++) scanf("%d", &ar[a][b]);
        ar[a][0]--, ar[a][1]--;
    }
    sort(p, p+m, comp);
    for(int a=0; a<m; a++)
    {
        int i=p[a];
        int l=find_se(ar[i][0]), r=find_se(ar[i][1]), va=ar[i][2];
        if(l==r)
        {
            if(us[l]==0)
            {
                us[l]=1, an+=va;
            }
        }
        else if(us[l]==1 and us[r]==0)
        {
            us[r]=1, an+=va;
        }
        else if(us[l]==0 and us[r]==1)
        {
            us[l]=1, an+=va;
        }
        else if(us[l]==0 and us[r]==0)
        {
            unite(l, r), an+=va;
        }
    }
    cout<<an;
}