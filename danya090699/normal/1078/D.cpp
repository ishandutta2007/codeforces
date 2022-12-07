#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10, inf=1e9;
int ll[16][sz], rr[16][sz], dot[16][sz*4][2];
void build(int i, int nu, int l, int r)
{
    if(l==r)
    {
        dot[i][nu][0]=ll[i][l];
        dot[i][nu][1]=rr[i][r];
    }
    else
    {
        int mid=(l+r)>>1;
        build(i, nu*2, l, mid);
        build(i, nu*2+1, mid+1, r);
        dot[i][nu][0]=min(dot[i][nu*2][0], dot[i][nu*2+1][0]);
        dot[i][nu][1]=max(dot[i][nu*2][1], dot[i][nu*2+1][1]);
    }
}
int lg, rg;
pair <int, int> que(int i, int nu, int l, int r)
{
    if(l>=lg and r<=rg) return {dot[i][nu][0], dot[i][nu][1]};
    else if(l>rg or r<lg) return {inf, -inf};
    else
    {
        int mid=(l+r)>>1;
        pair <int, int> lva=que(i, nu*2, l, mid), rva=que(i, nu*2+1, mid+1, r);
        return {min(lva.first, rva.first), max(lva.second, rva.second)};
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int q;
        scanf("%d", &q);
        for(int i=0; i<3; i++)
        {
            ll[0][i*n+a]=max(0, i*n+a-q);
            rr[0][i*n+a]=min(n*3-1, i*n+a+q);
        }
    }
    build(0, 1, 0, n*3);
    for(int i=1; i<16; i++)
    {
        for(int a=0; a<n*3; a++)
        {
            lg=ll[i-1][a], rg=rr[i-1][a];
            pair <int, int> re=que(i-1, 1, 0, n*3);
            ll[i][a]=re.first, rr[i][a]=re.second;
        }
        build(i, 1, 0, n*3);
    }
    for(int a=0; a<n; a++)
    {
        int cl=n+a, cr=n+a, su=0;
        for(int i=15; i>=0; i--)
        {
            lg=cl, rg=cr;
            pair <int, int> re=que(i, 1, 0, n*3);
            if(re.second-re.first+1<n)
            {
                cl=re.first, cr=re.second, su+=(1<<i);
            }
        }
        if(cr-cl+1<n) su++;
        printf("%d ", su);
    }
}