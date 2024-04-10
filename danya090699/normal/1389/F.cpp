#include <bits/stdc++.h>
using namespace std;
const int sz=4e5+10;
int dot[2][sz*4], add[2][sz*4];
void push(int i, int nu)
{
    add[i][nu*2]+=add[i][nu];
    add[i][nu*2+1]+=add[i][nu];
    add[i][nu]=0;
}
void recalc(int i, int nu)
{
    dot[i][nu]=max(dot[i][nu*2]+add[i][nu*2], dot[i][nu*2+1]+add[i][nu*2+1]);
}
int lg, rg, va;
void cha(int i, int nu, int l, int r)
{
    if(l>=lg and r<=rg) add[i][nu]+=va;
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        push(i, nu);
        cha(i, nu*2, l, mid);
        cha(i, nu*2+1, mid+1, r);
        recalc(i, nu);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    int ar[n][3], lq[2]={0, 0}, rq[2]={0, 0};
    map <int, int> ma;
    ma[0]=0;
    for(int a=0; a<n; a++)
    {
        int l, r, i;
        scanf("%d%d%d", &l, &r, &i);
        i--;
        lq[i]++, rq[i]++;
        ma[l]=0, ma[r]=0;
        ar[a][0]=l, ar[a][1]=r, ar[a][2]=i;
    }
    int m=0;
    for(auto it=ma.begin(); it!=ma.end(); it++) (*it).second=m++;

    vector <int> L[2][m], R[2][m];
    for(int a=0; a<n; a++)
    {
        int l=ma[ar[a][0]], r=ma[ar[a][1]], i=ar[a][2];
        L[i][l].push_back(r);
        R[i][r].push_back(l);
    }
    for(int i=0; i<2; i++)
    {
        lg=0, rg=0, va=lq[i], cha(i, 1, 0, m-1);
    }
    for(int a=1; a<m; a++)
    {
        for(int i=0; i<2; i++)
        {
            for(int b=0; b<L[i][a].size(); b++)
            {
                lg=a, rg=L[i][a][b], va=1;
                cha(i, 1, 0, m-1), lq[i]--;
            }
            for(int b=0; b<R[i][a].size(); b++)
            {
                lg=R[i][a][b], rg=a, va=-1;
                cha(i, 1, 0, m-1), rq[i]--;
            }
        }
        for(int i=0; i<2; i++)
        {
            int dp=dot[i^1][1]+add[i^1][1]-rq[i^1];
            an=max(an, dp);
            lg=a, rg=a, va=dp+lq[i];
            cha(i, 1, 0, m-1);
        }
    }
    cout<<an;
}