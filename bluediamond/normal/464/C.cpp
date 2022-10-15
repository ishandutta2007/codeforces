#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int add(int a,int b,int mod)
{
        a+=b;
        if(a>=mod)
                a-=mod;
        if(a<0)
                a+=mod;
        return a;
}

int mul(int a,int b,int mod)
{
        return a*(ll)b%mod;
}

int expow(int a,int b,int mod)
{
        int r=1;
        while(b)
        {
                if(b&1)
                        r=mul(r,a,mod);
                a=mul(a,a,mod);
                b>>=1;
        }
        return r;
}

pair <int,int> af[11]; /// {vl, ln}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

        string s;
        cin>>s;
        int cnt;
        cin>>cnt;
        vector<string>a(cnt);
        for(int i=0;i<cnt;i++)
                cin>>a[i];
        reverse(a.begin(),a.end());
        for(int i=0;i<=9;i++)
                af[i]={i,1};
        for(auto &b:a)
        {
                int x=b[0]-'0';
                vector<int>c;
                for(int j=2;j<b.size();j++)
                        c.push_back(b[j]-'0');
                /// x = c
                int cur=0,bef=0;
                reverse(c.begin(),c.end());
                for(auto &it:c)
                {
                        int a=af[it].first,b=af[it].second;
                        cur=add(cur,mul(a,expow(10,bef,(int)1e9+7),(int)1e9+7),(int)1e9+7);
                        bef=add(bef,b,(int)1e9+6);
                }
                af[x]={cur,bef};
        }
        int cur=0,bef=0;
        reverse(s.begin(),s.end());
        for(auto &it2:s)
        {
                int it=it2-'0';
                int a=af[it].first,b=af[it].second;
                cur=add(cur,mul(a,expow(10,bef,(int)1e9+7),(int)1e9+7),(int)1e9+7);
                bef=add(bef,b,(int)1e9+6);
        }
        cout<<cur<<"\n";
        return 0;
}