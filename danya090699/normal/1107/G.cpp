#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=3e5+10, inf=2e18;
int dot[sz*4], add[sz*4];
int lg, rg, va;
void push(int nu)
{
    add[nu*2]+=add[nu];
    add[nu*2+1]+=add[nu];
    add[nu]=0;
}
void recalc(int nu)
{
    dot[nu]=max(dot[nu*2]+add[nu*2], dot[nu*2+1]+add[nu*2+1]);
}
void cha(int nu, int l, int r)
{
    if(l>=lg and r<=rg) add[nu]+=va;
    else if(!(l>rg or r<lg))
    {
        push(nu);
        int mid=(l+r)>>1;
        cha(nu*2, l, mid);
        cha(nu*2+1, mid+1, r);
        recalc(nu);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, x, an=0;
    cin>>n>>x;
    int d[n], c[n];
    for(int a=0; a<n; a++) scanf("%lld%lld", &d[a], &c[a]);
    vector <pair <int, int> > st;
    st.push_back({inf, -1});
    for(int a=0; a<n; a++)
    {
        int cu=x-c[a];
        if(a)
        {
            int di=(d[a]-d[a-1])*(d[a]-d[a-1]);
            while(st.size())
            {
                if(st.back().first<di)
                {
                    rg=st.back().second, va=st.back().first-di;
                    st.pop_back();
                    lg=st.back().second+1;
                    cha(1, 0, n-1);
                }
                else break;
            }
            st.push_back({di, a-1});

            if(a>1)
            {
                lg=0, rg=a-2, va=x-c[a];
                cha(1, 0, n-1);
            }
            lg=a-1, rg=a-1, va=2*x-c[a]-c[a-1]-di;
            cha(1, 0, n-1);

            cu=max(cu, dot[1]+add[1]);
        }
        an=max(an, cu);
    }
    cout<<an;
}