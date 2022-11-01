#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    auto rng=[&](int l,int r)->int{return uniform_int_distribution<int>(l,r)(gen);};
    int n,m,p;
    cin >> n >> m >> p;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int e=100;
    int res=-1;
    string best;
    while(e--)
    {
        int a=rng(0,n-1);
        vector<int> opt;
        for(int i=0;i<m;i++) if(v[a][i]=='1') opt.push_back(i);
        int sz=opt.size();
        vector<int> sum((1<<sz),0);
        vector<string> now(n);
        for(int i=0;i<n;i++)
        {
            int t=0;
            for(int j=0;j<sz;j++) if(v[i][opt[j]]=='1') t^=(1<<j);
            sum[t]++;
        }
        for(int i=0;i<sz;i++) for(int j=(1<<sz)-1;j>=0;j--) if((j&(1<<i))==0) sum[j]+=sum[j^(1<<i)];
        for(int i=0;i<(1<<sz);i++)
        {
            if(sum[i]>=(n+1)/2)
            {
                int pc=0;
                for(int j=0;j<sz;j++) pc+=((i>>j)&1);
                if(pc>res)
                {
                    res=pc;
                    best=string(m,'0');
                    for(int j=0;j<sz;j++) if((i>>j)&1) best[opt[j]]='1';
                }
            }
        }
    }
    cout << best << "\n";
    return 0;
}