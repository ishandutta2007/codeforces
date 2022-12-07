#include <bits/stdc++.h>
using namespace std;
const int sz=5e5, inf=1e9;
pair <int, int> dot[sz*4];
int lg, rg, pp, ar[sz], ne[sz];
void cha(int nu, int l, int r)
{
    if(l==r) dot[nu]=make_pair(ne[l], ar[l]);
    else
    {
        int mid=(l+r)>>1;
        if(pp<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);
        dot[nu]=max(dot[nu*2], dot[nu*2+1]);
    }
}
pair <int, int> que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[nu];
    else if(l>rg or r<lg) return make_pair(-1, -1);
    else
    {
        int mid=(l+r)>>1;
        return max(que(nu*2, l, mid), que(nu*2+1, mid+1, r));
    }
}
vector <int> sp[sz];
int zap[sz][2], p[sz], an[sz];
bool comp(int a, int b){return zap[a][0]<zap[b][0];}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        sp[ar[a]].push_back(a);
    }
    for(int a=0; a<sz; a++)
    {
        if(sp[a].size())
        {
            for(int b=0; b+1<sp[a].size(); b++) ne[sp[a][b]]=sp[a][b+1];
            ne[sp[a].back()]=inf;
            pp=sp[a][0], cha(1, 0, n-1);
        }
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        scanf("%d%d", &zap[a][0], &zap[a][1]);
        zap[a][0]--, zap[a][1]--;
        p[a]=a;
    }
    sort(p, p+q, comp);
    int yk=0;
    for(int a=0; a<n; a++)
    {
        while(yk<q)
        {
            int i=p[yk];
            if(zap[i][0]==a)
            {
                lg=a, rg=zap[i][1];
                pair <int, int> re=que(1, 0, n-1);
                if(re.first>rg) an[i]=re.second;
                else an[i]=0;
                yk++;
            }
            else break;
        }
        if(ne[a]!=inf)
        {
            pp=ne[a], cha(1, 0, n-1);
        }
        ne[a]=0, pp=a, cha(1, 0, n-1);
    }
    for(int a=0; a<q; a++) printf("%d\n", an[a]);
}