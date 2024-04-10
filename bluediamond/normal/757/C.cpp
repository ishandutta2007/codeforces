#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod=(int)1e9+7;

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

const int nax=(int)1e6+7;
int f[nax];

struct kuk
{
        int a,b,c;
};

bool operator < (kuk f,kuk s)
{
        if(f.a!=s.a) return f.a<s.a;
        if(f.b!=s.b) return f.b<s.b;
        return f.c<s.c;
}

int main()
{
        bool is_home=0;

        if(is_home)
        {
                freopen("__input__","r",stdin);
        }
        else
        {
                ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        }

        f[0]=1;
        for(int i=1;i<nax;i++)
                f[i]=mul(f[i-1],i);

        int n,m;
        cin>>n>>m;
        int baz1=(int)1e6+3;
        int baz2=(int)1e9+4;
        int baz3=(int)1e9+5;
        map <kuk,int> fr;
        vector <kuk> hsh(m);
        for(int i=0;i<m;i++)
                hsh[i]={0,0};

        int now1=1;
        int now2=1;
        int now3=1;

        for(int i=0;i<n;i++)
        {
                int cnt;
                cin>>cnt;
                map <int,int> mt;
                for(int j=0;j<cnt;j++)
                {
                        int x;
                        cin>>x;
                        x--;
                        mt[x]++;
                }
                for(auto &it : mt)
                {
                        int x=it.first,y=it.second;
                        hsh[x]={add(hsh[x].a,mul(y,now1)),add(hsh[x].b,mul(y,now2)),add(hsh[x].c,mul(y,now3))};
                }
                now1=mul(now1,baz1);
                now2=mul(now2,baz2);
                now3=mul(now3,baz3);
        }


        for(auto &h : hsh)
                fr[h]++;

        int ans=1;
        for(auto &it : fr)
                ans=mul(ans,f[it.second]);
        cout<<ans<<"\n";

        return 0;
}