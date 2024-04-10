#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
int a[500005];
set<pll>one;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int zero=0,two=-1,sign=1;
        ll shifter=0;
        one.clear();
        for(int i=1;i<=n;i++)
        {
            int x=a[i];
            if(two!=-1)
            {
                zero+=2;
                one.clear();
                shifter=0,sign=1;
                if(x-two>0)one.insert(mp(x-two,x-two));
            }
            else if(one.size())
            {
                if(sign==1)//x-t>0 <-> t<=x-1
                {
                    while(one.size()&&shifter+one.rbegin()->fi>=x)one.erase(*one.rbegin());
                    if(one.size()&&shifter+one.rbegin()->se>=x)
                    {
                        ll tmp=one.rbegin()->fi;
                        one.erase(*one.rbegin());
                        one.insert(mp(tmp,x-shifter-1));
                    }
                }
                else
                {
                    while(one.size()&&shifter-one.begin()->se>=x)one.erase(*one.begin());
                    if(one.size()&&shifter-one.begin()->fi>=x)
                    {
                        ll tmp=one.begin()->se;
                        one.erase(*one.begin());
                        one.insert(mp(shifter-x+1,tmp));
                    }
                }
                zero++,sign*=-1,shifter=x-shifter;
            }
            else
            {
                shifter=x,sign=-1;
                if(i-1)one.insert(mp(1,min(a[i-1],x)-1));
            }
            two=-1;
            if(x&1)continue;
            int c=(x>>1);//shifter+sign*t=c <-> t=sign*(c-shifter)
            ll t=sign*(c-shifter);auto it=one.lower_bound(mp(t+1,t+1));
            bool flag=0;
            if(it!=one.begin())
            {
                it--;
                if(it->fi<=t&&it->se>=t)
                {
                    ll t1=it->fi,t2=it->se;
                    one.erase(it);
                    if(t1!=t)one.insert(mp(t1,t-1));
                    if(t2!=t)one.insert(mp(t+1,t2));
                    two=c;flag=1;
                }
            }
            if(!flag)one.insert(mp(t,t));
        }
        if(two!=-1)printf("%d\n",2*n-zero-2);
        else if(one.size())printf("%d\n",2*n-zero-1);
        else printf("%d\n",2*n-zero);
    }
    return 0;
}