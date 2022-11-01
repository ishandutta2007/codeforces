#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector t(k+1,vector(1<<k,bool(0)));
    t[0][0]=1;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        for(int j=1;j<=k;j++) t[j][x>>(k-j)]=1;
    }
    auto zero=[&](int a,int l,int y)->bool{return t[l+1][2*a+y];};
    auto one=[&](int a,int l,int y)->bool{return t[l+1][2*a+(y^1)];};
    vector best(k,vector(1<<k,int(1<<k)));
    auto chmin=[&](int &a,int b){a=min(a,b);};
    for(int s=0;s<k;s++)
    {
        for(int i=0;i<(1<<s);i++)
        {
            for(int x=0;x<(1<<(k-s));x++)
            {
                int a=2*i+1;
                int b=2*i;
                if(!t[s+1][a]||!t[s+1][b]) continue;
                if(x&(1<<(k-(s+1)))) swap(a,b);
                int d=(1<<(k-(s+1)));
                for(int l=s+1;l<k;l++)
                {
                    int y=(x>>(k-(l+1)))&1;
                    if(zero(a,l,y)&&one(b,l,y))
                    {
                        a=2*a+y;
                        b=2*b+(y^1);
                        d-=(1<<(k-(l+1)));
                    }
                    else if(zero(a,l,y)&&zero(b,l,y))
                    {
                        a=2*a+y;
                        b=2*b+y;
                    }
                    else if(one(a,l,y)&&one(b,l,y))
                    {
                        a=2*a+(y^1);
                        b=2*b+(y^1);
                    }
                    else if(one(a,l,y)&&zero(b,l,y))
                    {
                        a=2*a+(y^1);
                        b=2*b+y;
                        d+=(1<<(k-(l+1)));
                    }
                    else assert(0);
                }
                chmin(best[s][x],d);
            }
        }
    }
    for(int x=0;x<(1<<k);x++)
    {
        int res=(1<<k);
        for(int s=0;s<k;s++) chmin(res,best[s][x&((1<<(k-s))-1)]);
        cout << res << " \n"[x==(1<<k)-1];
    }
    return 0;
}