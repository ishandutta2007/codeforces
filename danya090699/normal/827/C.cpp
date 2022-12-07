//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10;
vector <int> dot[4][10][10];
int ar[sz], n, qq, le, x, y, lg, rg, add;
void recalc(int nu){dot[le][x][y][nu]=dot[le][x][y][nu*2]+dot[le][x][y][nu*2+1];}
void build(int nu, int l, int r)
{
    if(l==r)
    {
        if(ar[y+l*(x+1)]==le) dot[le][x][y][nu]=1;
        else dot[le][x][y][nu]=0;
    }
    else
    {
        int mid=(l+r)/2;
        build(nu*2, l, mid);
        build(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
void cha(int nu, int l, int r)
{
    if(l==r) dot[le][x][y][nu]=add;
    else
    {
        int mid=(l+r)/2;
        if(lg<=mid) cha(nu*2, l, mid);
        else cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
int que(int nu, int l, int r)
{
    if(l>=lg and r<=rg) return dot[le][x][y][nu];
    else if(l>rg or r<lg) return 0;
    else
    {
        int mid=(l+r)/2;
        return que(nu*2, l, mid)+que(nu*2+1, mid+1, r);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    n=s.size();
    for(int a=0; a<n; a++)
    {
        if(s[a]=='A') ar[a]=0;
        if(s[a]=='T') ar[a]=1;
        if(s[a]=='G') ar[a]=2;
        if(s[a]=='C') ar[a]=3;
    }
    for(int a=0; a<4; a++)
    {
        le=a;
        for(int b=0; b<10; b++)
        {
            x=b;
            for(int c=0; c<=b; c++)
            {
                y=c;
                int q=n-c;
                if(q>0)
                {
                    q=(q-1)/(x+1)+1;
                    dot[le][x][y].resize(q*4);
                    build(1, 0, q-1);
                }
            }
        }
    }
    cin>>qq;
    for(int a=0; a<qq; a++)
    {
        int ty, l, r;
        scanf("%d%d", &ty, &l);
        l--;
        if(ty==1)
        {
            char sy;
            cin>>sy;
            int l1=ar[l], l2;
            if(sy=='A') l2=0;
            if(sy=='T') l2=1;
            if(sy=='G') l2=2;
            if(sy=='C') l2=3;
            for(int b=0; b<10; b++)
            {
                x=b, y=l%(b+1), lg=l/(b+1);
                int q=(n-y-1)/(x+1)+1;
                le=l1, add=0;
                cha(1, 0, q-1);
                le=l2, add=1;
                cha(1, 0, q-1);
            }
            ar[l]=l2;
        }
        else
        {
            scanf("%d", &r);
            string t;
            cin>>t;
            int m=t.size(), an=0;
            x=m-1;
            for(int b=0; b<m; b++)
            {
                if(t[b]=='A') le=0;
                if(t[b]=='T') le=1;
                if(t[b]=='G') le=2;
                if(t[b]=='C') le=3;
                y=(l+b)%m;
                int q=(n-y-1)/(x+1)+1;
                if(l+b<r)
                {
                    lg=0, rg=(r-(y+1))/m;
                    if(y<l) lg=(l-y-1)/m+1;
                    an+=que(1, 0, q-1);
                }
            }
            printf("%d\n", an);
        }
    }
}