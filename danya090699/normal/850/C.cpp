#include <bits/stdc++.h>
#define iter map <int, int>::iterator
using namespace std;
map <int, int> dp;
int f(int st)
{
    if(dp.find(st)==dp.end())
    {
        set <int> fr;
        for(int a=0; (1<<a)<=st; a++)
        {
            int x=st&((1<<a)-1), y=(st>>(a+1));
            fr.insert(f(x|y));
        }
        for(int a=0; ; a++)
        {
            if(fr.find(a)==fr.end())
            {
                dp[st]=a;
                break;
            }
        }
    }
    return dp[st];
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    map <int, int> ma;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        for(int b=2; b*b<=x; b++)
        {
            if(x%b==0)
            {
                int q=0;
                while(x%b==0)
                {
                    x/=b, q++;
                }
                ma[b]|=(1<<(q-1));
            }
        }
        if(x>1) ma[x]|=1;
    }
    for(iter it=ma.begin(); it!=ma.end(); it++)
    {
        dp.clear(), dp[0]=0;
        an^=f((*it).second);
    }
    if(an==0) cout<<"Arpa";
    else cout<<"Mojtaba";
}