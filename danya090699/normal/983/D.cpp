#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
set <int, greater <int> > dot[sz*4];
int mi[sz*4*2+10], ma[sz*4*2+10], m=0;
int lg, rg, ty, va;
bool us[sz];
void recalc(int nu)
{
    int co=-1;
    if(dot[nu].size()) co=*dot[nu].begin();
    mi[nu]=max(co, min(mi[nu*2], mi[nu*2+1]));
    if(co>max(ma[nu*2], ma[nu*2+1]))
    {
        if(us[co]) ma[nu]=-1;
        else
        {
            if(min(mi[nu*2], mi[nu*2+1])<co) ma[nu]=co;
            else ma[nu]=-1;
        }
    }
    else ma[nu]=max(ma[nu*2], ma[nu*2+1]);
}
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg)
    {
        if(ty==0) dot[nu].insert(va);
        if(ty==1) dot[nu].erase(va);
    }
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
    }
    recalc(nu);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    map <int, int> may;
    pair <int, int> sp[n*2];
    int ar[n][4];
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<4; b++) scanf("%d", &ar[a][b]);
        sp[a*2]=make_pair(ar[a][0], a);
        sp[a*2+1]=make_pair(ar[a][2], a);
        may[ar[a][1]]=0, may[ar[a][3]]=0;
    }
    for(auto it=may.begin(); it!=may.end(); it++)
    {
        (*it).second=m, m++;
    }
    for(int a=0; a<m*4*2+10; a++)
    {
        mi[a]=-1, ma[a]=-1;
    }
    sort(sp, sp+n*2);
    int yk=0, an=1;
    while(yk<n*2)
    {
        int cu=sp[yk].first;
        while(yk<n*2)
        {
            if(sp[yk].first==cu)
            {
                int i=sp[yk].second;
                int x1=ar[i][0], y1=ar[i][1], x2=ar[i][2], y2=ar[i][3];
                lg=may[y1], rg=may[y2]-1, va=i;
                if(cu==x1) ty=0;
                else ty=1;
                cha(1, 0, m-1);
                yk++;
            }
            else break;
        }
        while(ma[1]!=-1)
        {
            int i=ma[1];
            us[i]=1, lg=may[ar[i][1]], rg=may[ar[i][3]]-1, ty=2;
            cha(1, 0, m-1);
            an++;
        }
    }
    cout<<an;
}