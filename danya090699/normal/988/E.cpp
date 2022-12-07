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
    reverse(ch.begin(), ch.end());
    int n=ch.size();
    for(int a=0; a<n; a++)
    {
        for(int b=a+1; b<n; b++)
        {
            int f0=-1, fn0=-1;
            vector <int> sp;
            for(int c=0; c<n; c++) if(c!=a and c!=b) sp.push_back(ch[c]);
            if(sp.size())
            {
                if(sp[0]==0) f0=0;
            }
            for(int c=0; c<sp.size(); c++)
            {
                if(sp[c]!=0 and fn0==-1) fn0=c;
            }
            if((ch[a]*10+ch[b])%25==0)
            {
                int va=(n-2)-a+(n-1)-b;
                if(f0!=-1)
                {
                    if(fn0!=-1) va+=fn0-f0;
                    else va=inf;
                }
                an=min(an, va);
            }
            if((ch[b]*10+ch[a])%25==0)
            {
                int va=(n-2)-a+(n-1)-b+1;
                if(f0!=-1)
                {
                    if(fn0!=-1) va+=fn0-f0;
                    else va=inf;
                }
                an=min(an, va);
            }
        }
    }
    if(an!=inf) cout<<an;
    else cout<<-1;
}