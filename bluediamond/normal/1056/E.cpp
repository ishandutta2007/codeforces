#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD=(int)1e9+7;

int add(int a,int b)
{
    a+=b;
    if(a>=MOD) a-=MOD;
    if(a<0) a+=MOD;
    return a;
}

int mul(int a,int b)
{
    return a*(long long)b%MOD;
}

int expow(int a,int b)
{
    int r=1;
    while(b)
    {
        if(b&1)
        {
            r=mul(r,a);
        }
        a=mul(a,a);
        b>>=1;
    }
    return r;
}

const int N=(int)1e6+7;

string t,s;
int m,n;

int prefix[N];
int inv[N];

int gt(int l,int r)
{
    l++, r++;
    int sum=add(prefix[r],-prefix[l-1]);
    return mul(sum,inv[l-1]);
}

int ml(int mask,int len,int cnt)
{
    int a=expow(26,len*cnt); a=add(a,-1);
    int b=expow(26,len); b=add(b,-1);
    a=mul(a,mask);
    return mul(a,expow(b,MOD-2));
}

/// 26^0 + 26^3 + 26^6 + 26^9


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t>>s;
    m=t.size(), n=s.size();
    inv[N-1]=expow(expow(26,N-1),MOD-2);
    for(int i=N-2;i>=0;i--)
    {
        inv[i]=mul(inv[i+1],26);
    }
    for(int i=0;i<n;i++)
    {
        prefix[i+1]=prefix[i];
        prefix[i+1]=add(prefix[i],mul(expow(26,i),s[i]-'a'));
    }
    vector<pair<int,int>>kek;
    int f0=0;
    for(auto &it:t)
    {
        int x=it-'0';
        f0+=(x==0);
        if(kek.empty() || x!=kek.back().first)
        {
            kek.push_back({x,0});
        }
        kek.back().second++;
    }
    /**

    0101010
    abcabc

    **/
  ///  cout<<ml(gt(0,2),3,2)<<"\n";
   /// cout<<gt(0,5)<<"\n";
   // return 0;
  //  cout<<ml(gt(0,3),4,2)<<"\n";
  //  cout<<gt(0,7)<<"\n";
  ///  return 0;
    int res=0;
    for(int b=1;b<=n;b++)
    {
        ll val=n-b*m+b*f0;
        if(val%f0) continue;
        if(val/(ll)f0<=0 || val/(ll)f0>n) continue;
        int a=val/(ll)f0;
        int ma=0;
        int mb=0;
        int poz=0;
        for(auto &it:kek)
        {
            int x=it.first,f=it.second;
            if(x==0)
            {
                ma=gt(poz,poz+a-1);
                poz+=a*f;
            }
            else
            {
                mb=gt(poz,poz+b-1);
                poz+=b*f;
            }
        }
        poz=0;
        bool ok=1;
        if(a==b && ma==mb) continue;
     ///   cout<<a<<" , "<<b<<" : "<<ma<<" , "<<mb<<"\n";
        bool pr=0;
        if(a==4)
        {
                pr=1;
        }
        for(auto &it:kek)
        {
            int x=it.first,f=it.second;
            if(x==0)
            {
                int vl=gt(poz,poz+a*f-1);
                /**if(pr)
                {
                        cout<<"KEK : "<<vl<<" , "<<ml(ma,a,f)<<"\n";
                }**/
              ///  cout<<vl<<" "<<ml(ma,a,f)<<" , ";
                if(vl!=ml(ma,a,f))
                {
                    ok=0;
                }
                poz+=a*f;
            }
            else
            {
                int vl=gt(poz,poz+b*f-1);
                /**if(pr)
                {
                        cout<<"KEK : "<<vl<<" , "<<ml(mb,b,f)<<"\n";
                }**/
                if(vl!=ml(mb,b,f))
                {
                    ok=0;
                }
                poz+=b*f;
            }
        }
        ///cout<<a<<" , "<<b<<" : "<<ok<<"\n";
        res+=ok;
    ///    cout<<ma<<" "<<mb<<"\n";
    }
    cout<<res<<"\n";
    return 0;
    for(auto &it:kek)
    {
        cout<<" --> "<<it.first<<" , "<<it.second<<"\n";
    }
    return 0;
}