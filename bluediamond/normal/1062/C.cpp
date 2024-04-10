#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD=1000000007;

inline int add(int a,int b)
{
    a+=b;
    if(a>=MOD)
    {
        a-=MOD;
    }
    if(a<0)
    {
        a+=MOD;
    }
    return a;
}

inline int mul(int a,int b)
{
    return a*(long long)b%MOD;
}

inline int expow(int a,int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=mul(ans,a);
        }
        a=mul(a,a);
        b>>=1;
    }
    return ans;
}

const int N=100000+5;

int n,q;
int p[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
    {
        p[i]=p[i-1]+(s[i-1]-'0');
    }
    while(q--)
    {
        int st,dr;
        cin>>st>>dr;
        int cnt1=p[dr]-p[st-1];
        int cnt0=(dr-st+1)-cnt1;
      ///  cout<<"\t"<<cnt1<<" "<<cnt0<<"\n";
        int ans=add(expow(2,cnt1),-1);
        int val=ans;
        val=mul(val,expow(2,cnt0)-1);
        ans=add(ans,val);
        cout<<ans<<"\n";
    }
    return 0;
}
/**

**/