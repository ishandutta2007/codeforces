#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int mod=998244353;

int add(int a,int b)
{
        a+=b;
        if(a>=mod)
                return a-mod;
        if(a<0)
                return a+mod;
        return a;
}

int mul(int a,int b)
{
        return a*(ll)b%mod;
}

int expow(int a,int b)
{
        int r=1;
        while(b)
        {
                if(b&1)
                        r=mul(r,a);
                a=mul(a,a);
                b/=2;
        }
        return r;
}

const int N=(int)3e5+7;
int n;

struct kek
{
        int a;
        int b;
};

bool operator < (kek f,kek s)
{
        if(f.a!=s.a)
                return f.a<s.a;
        return f.b<s.b;
}

map <kek,int> cnt;

bool cmpa(kek f,kek s) {if(f.a!=s.a) return f.a<s.a; return f.b<s.b;}
bool cmpb(kek f,kek s) {if(f.b!=s.b) return f.b<s.b; return f.a<s.a;}

kek v[N];
int f[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

      //  freopen("input","r",stdin);

        cin>>n;
        for(int i=1;i<=n;i++)
        {
                cin>>v[i].a>>v[i].b;
                cnt[v[i]]++;
        }
        f[0]=1;
        for(int i=1;i<=n;i++)
                f[i]=mul(f[i-1],i);
        sort(v+1,v+n+1,cmpa);
        int yes=1;
        for(int i=2;i<=n;i++)
                if(v[i-1].b>v[i].b)
                        yes=0;
        int coc=yes;
        for(auto &x : cnt)
                coc=mul(coc,f[x.second]);
        int i=1,cur=1;
        while(i<=n)
        {
                int j=i;
                while(j+1<=n && v[i].a==v[j+1].a)
                        j++;
                cur=mul(cur,f[j-i+1]);
                i=j+1;
        }
        int res=f[n];
        res=add(res,coc);
        res=add(res,-cur);
        sort(v+1,v+n+1,cmpb);
        i=1,cur=1;
        while(i<=n)
        {
                int j=i;
                while(j+1<=n && v[i].b==v[j+1].b)
                        j++;
                cur=mul(cur,f[j-i+1]);
                i=j+1;
        }
        res=add(res,-cur);
        cout<<res<<"\n";

        return 0;
}