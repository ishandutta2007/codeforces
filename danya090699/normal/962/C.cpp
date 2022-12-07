#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e9;
main()
{
    //freopen("input.txt", "r", stdin);
    int x, an=inf;
    cin>>x;
    vector <int> ch;
    while(x)
    {
        ch.push_back(x%10), x/=10;
    }
    int n=ch.size();
    for(int i=1; i<(1<<n); i++)
    {
        int x=0, st=0, q=0;
        for(int a=n-1; a>=0; a--)
        {
            if(i&(1<<a))
            {
                if(st==0)
                {
                    if(ch[a]==0) break;
                    st=1;
                }
                x=x*10+ch[a];
            }
            else q++;
        }
        if(x)
        {
            int l=0, r=1e5;
            while(r-l>1)
            {
                int mid=(l+r)>>1;
                if(mid*mid<=x) l=mid;
                else r=mid;
            }
            if(l*l==x) an=min(an, q);
        }
    }
    if(an==inf) cout<<-1;
    else cout<<an;
}