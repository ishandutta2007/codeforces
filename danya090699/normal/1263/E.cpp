#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
int mi[sz*4], ma[sz*4], add[sz*4];
void push(int nu)
{
    add[nu*2]+=add[nu];
    add[nu*2+1]+=add[nu];
    add[nu]=0;
}
void recalc(int nu)
{
    mi[nu]=min(mi[nu*2]+add[nu*2], mi[nu*2+1]+add[nu*2+1]);
    ma[nu]=max(ma[nu*2]+add[nu*2], ma[nu*2+1]+add[nu*2+1]);
}
int lg, rg, va;
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg) add[nu]+=va;
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        push(nu);
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
char s[sz], s2[sz];
main()
{
    //freopen("input.txt", "r", stdin);
    int n, p=0, su=0;
    cin>>n;
    scanf("%s", s);
    for(int a=0; a<n; a++)
    {
        if(s[a]=='L') p=max(0, p-1);
        else if(s[a]=='R') p++;
        else
        {
            lg=p, rg=n-1, va=0;
            if(s2[p]=='(') va--;
            if(s2[p]==')') va++;

            s2[p]=s[a];

            if(s2[p]=='(') va++;
            if(s2[p]==')') va--;

            if(va!=0) cha(1, 0, n-1);

            su+=va;
        }

        if(mi[1]+add[1]>=0 and su==0) printf("%d ", ma[1]+add[1]);
        else printf("-1 ");
    }
}