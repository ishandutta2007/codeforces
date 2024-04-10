#include <bits/stdc++.h>
using namespace std;
int *dot, pos, add, cu;
void recalc(int nu)
{
    dot[nu]=dot[nu*2]+dot[nu*2+1];
}
void cha(int nu, int l, int r)
{
    if(l==r) dot[nu]+=add;
    else
    {
        int mid=(l+r)/2;
        if(pos<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int que(int nu, int l, int r)
{
    if(l==r)
    {
        if(dot[nu]>cu) return l;
        else return l+1;
    }
    else
    {
        int mid=(l+r)/2;
        if(dot[nu*2]>cu) return que(nu*2, l, mid);
        else
        {
            cu-=dot[nu*2];
            return que(nu*2+1, mid+1, r);
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], an[n];
    vector <int> ch[n], per[n+1];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a], ar[a]--;
    }
    for(int a=n-1; a>=0; a--) ch[ar[a]].push_back(a);
    for(int a=1; a<=n; a++) per[0].push_back(a);
    dot=new int[n*4];
    for(int a=0; a<n*4; a++) dot[a]=0;
    add=1;
    for(int a=0; a<n; a++)
    {
        if(ch[a].size()!=0)
        {
            pos=ch[a].back();
            cha(1, 0, n-1);
        }
        an[a]=0;
    }
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<per[a].size(); b++)
        {
            cu=per[a][b];
            int np=que(1, 0, n-1);
            an[per[a][b]-1]++;
            per[np].push_back(per[a][b]);

        }
        pos=a, add=-1;
        cha(1, 0, n-1);
        ch[ar[a]].pop_back();
        if(ch[ar[a]].size()!=0)
        {
            pos=ch[ar[a]].back(), add=1;
            cha(1, 0, n-1);
        }
    }
    for(int a=0; a<n; a++) cout<<an[a]<<" ";
}