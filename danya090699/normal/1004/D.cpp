#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
int t, q[sz], q2[sz];
bool check(int n, int m, int x, int y)
{
    for(int a=0; a<t; a++) q2[a]=0;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<m; b++) q2[abs(a-x)+abs(b-y)]++;
    }
    bool ok=1;
    for(int a=0; a<t; a++)
    {
        if(q[a]!=q2[a])
        {
            ok=0;
            break;
        }
    }
    return ok;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>t;
    int ma=0, mi, n=-1, m, x, y;
    for(int a=0; a<t; a++)
    {
        int x;
        scanf("%d", &x);
        ma=max(ma, x);
        q[x]++;
    }
    for(int a=1; a<=t; a++)
    {
        if(q[a]<a*4)
        {
            mi=a-1;
            break;
        }
    }
    for(int a=1; a*a<=t; a++)
    {
        if(t%a==0)
        {
            int b=t/a;
            if(a-1>=mi)
            {
                int d=ma-(a-1-mi);
                if(d>=0 and d<b)
                {
                    if(check(a, b, mi, d))
                    {
                        n=a, m=b, x=mi, y=d;
                        break;
                    }
                }
            }
            if(b-1>=mi)
            {
                int d=ma-(b-1-mi);
                if(d>=0 and d<a)
                {
                    if(check(a, b, d, mi))
                    {
                        n=a, m=b, x=d, y=mi;
                        break;
                    }
                }
            }
        }
    }
    if(n!=-1) cout<<n<<" "<<m<<"\n"<<x+1<<" "<<y+1;
    else cout<<-1;
}