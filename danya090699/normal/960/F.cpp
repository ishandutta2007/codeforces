#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> dot[sz];
int lg, rg, p, va;
void cha(int i, int nu, int l, int r)
{
    if(l==r) dot[i][nu]=max(dot[i][nu], va);
    else
    {
        int mid=(l+r)>>1;
        if(p<=mid) cha(i, nu*2, l, mid);
        else cha(i, nu*2+1, mid+1, r);
        dot[i][nu]=max(dot[i][nu*2], dot[i][nu*2+1]);
    }
}
int que(int i, int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[i][nu];
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)>>1;
        return max(que(i, nu*2, l, mid), que(i, nu*2+1, mid+1, r));
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, an=0;
    cin>>n>>m;
    map <int, int> ma[n];
    int re[m][3];
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<3; b++) scanf("%d", &re[a][b]);
        re[a][0]--, re[a][1]--;
        ma[re[a][1]][re[a][2]]=0;
    }
    for(int a=0; a<n; a++)
    {
        ma[a][-1]=0;
        int m=0;
        for(auto it=ma[a].begin(); it!=ma[a].end(); it++)
        {
            (*it).second=m, m++;
        }
        dot[a].resize(ma[a].size()*4);
    }
    for(int a=0; a<m; a++)
    {
        int u=re[a][0], v=re[a][1], pr=re[a][2];
        auto it=ma[u].lower_bound(pr);
        it--;
        lg=0, rg=(*it).second;
        va=que(u, 1, 0, ma[u].size()-1)+1;
        an=max(an, va);
        p=ma[v][pr];
        cha(v, 1, 0, ma[v].size()-1);
    }
    cout<<an;
}