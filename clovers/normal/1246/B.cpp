#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
void checkmin(int &x,int y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
const int N=200005;
int n,t[N],a[N],k;

ll qpow(ll x,int y)
{
    ll ret=1;
    while(y)
    {
        if(y&1) ret=ret*x;
        if(ret>100000) return 0;
        if(x>1e5) return 0;
        x=x*x;
        y>>=1;
    }
    return ret;
}

int init(int x)
{
    int tmp=1;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            int now=0;
            while(x%i==0) x/=i,now++;
            now=now%k;
            tmp=tmp*qpow(i,now);
        }
    }
    return tmp*x;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]=init(a[i]);
        t[a[i]]++;
    }
    //for(int i=1;i<=9;i++) cout<<t[i]<<endl;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        t[a[i]]--;
        ll now=1,tmp=a[i];
        for(int x=2;x*x<=tmp;x++) 
        {
            if(tmp%x==0) 
            {
                int ti=0;
                while(tmp%x==0) 
                {
                    tmp/=x,ti++;
                }
                now=now*qpow(x,k-ti);
                if(now>100000) now=0;
            }
        }
        if(tmp>0) now=now*qpow(tmp,k-1);
        if(now>100000||now==0) continue;
        ans+=t[now]; 
    }
    cout<<ans<<endl;
    return 0;
}