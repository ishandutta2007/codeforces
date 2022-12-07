#include <bits/stdc++.h>
using namespace std;
const int sz=(1<<21);
int q[sz];
bitset <sz*2> us, us2;
vector <int> sp;
void dfs(int x)
{
    us2[x]=1, sp.push_back(x);
    if(q[x]<2) q[x]++;
    if(q[x]==2)
    {
        int cu=1;
        for(int i=20; i>=0; i--)
        {
            cu<<=1;
            if(x&(1<<i)) cu++;
            us[cu]=1;
        }
    }
    for(int i=0; i<=20; i++)
    {
        if(x&(1<<i))
        {
            int ne=x^(1<<i);
            if(q[ne]<2 and us2[ne]==0) dfs(ne);
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    for(int a=n-1; a>=0; a--)
    {
        if(a+2<n)
        {
            int cu=1, va=0;
            for(int i=20; i>=0; i--)
            {
                cu<<=1;
                if(ar[a]&(1<<i)) va+=(1<<i);
                else
                {
                    if(us[cu+1]) va+=(1<<i), cu++;
                }
            }
            an=max(an, va);
        }
        dfs(ar[a]);
        for(int b=0; b<sp.size(); b++) us2[sp[b]]=0;
        sp.clear();
    }
    cout<<an;
}