#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
typedef long long ll;

struct counter
{
    ll x=0,y=0,z=0,xy=0,yz=0,xyz=0;
    void add_x(){x++;}
    void add_y(){y++;xy+=x;}
    void add_z(){z++;yz+=y;xyz+=xy;}
};

struct summer
{
    ll x=0,xy=0,xyz=0;
    void add_counter(counter c)
    {
        xyz+=(x*c.yz+xy*c.z+c.xyz);
        xy+=(x*c.y+c.xy);
        x+=(c.x);
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> a(n);
    vector<int> b0(n);
    vector<int> c0(n);
    for(int i=0;i<n;i++){cin >> a[i]; a[i]--;}
    for(int i=0;i<n;i++){cin >> b0[i]; b0[i]--;}
    for(int i=0;i<n;i++){cin >> c0[i]; c0[i]--;}
    const int N=450;
    const int Q=250;
    vector<int> b(n);
    vector<int> c(n);
    for(int i=0;i<n;i++)
    {
        b[i]=b0[a[i]];
        c[i]=c0[a[i]];
    }
    vector<int> tp(q,0);
    vector<array<int,2>> queries(q,{0,0});
    vector<ll> res(q,0);
    for(int o=0;o<q;o++)
    {
        auto &[x,y]=queries[o];
        cin >> tp[o] >> x;
        if(tp[o]==1) cin >> y;
        x--; y--;
    }
    vector<vector<array<int,2>>> val_starts(n);
    for(int i=0;i<n;i++)
    {
        val_starts[b[i]].push_back({i,0});
        val_starts[a[i]].push_back({i,1});
        val_starts[c[i]].push_back({i,2});
    }
    vector<vector<array<int,3>>> val_changes(n);
    vector<vector<array<int,2>>> val_ends(n);
    vector<vector<int>> dynamic_queries(n);
    vector<bool> is_static(n,1);
    vector<vector<int>> static_queries(n);
    vector<array<ll,2>> dp(n,{0,0});
    for(int ql=0;ql<q;ql+=Q)
    {
        int qr=min(q,ql+Q);
        for(int o=ql;o<qr;o++)
        {
            if(tp[o]==1)
            {
                auto [k,x]=queries[o];
                val_changes[b[k]].push_back({o,k,0});
                val_changes[a[k]].push_back({o,k,1});
                val_changes[c[k]].push_back({o,k,2});
                is_static[b[k]]=is_static[a[k]]=is_static[c[k]]=0;
                a[k]=x;
                b[k]=b0[a[k]];
                c[k]=c0[a[k]];
                val_changes[b[k]].push_back({o,k,0});
                val_changes[a[k]].push_back({o,k,1});
                val_changes[c[k]].push_back({o,k,2});
                is_static[b[k]]=is_static[a[k]]=is_static[c[k]]=0;
            }
            else
            {
                int r=queries[o][0];
                static_queries[r].push_back(o);
            }
        }
        for(int i=0;i<n;i++) if(!is_static[i]) dynamic_queries[i].push_back(ql);
        ll now=0;
        for(int i=0;i<n;i++)
        {
            if(is_static[c[i]]) now+=dp[c[i]][1];
            if(is_static[a[i]]) dp[a[i]][1]+=dp[a[i]][0];
            if(is_static[b[i]]) dp[b[i]][0]++;
            for(int o:static_queries[i]) res[o]+=now;
        }
        for(int i=0;i<n;i++)
        {
            is_static[i]=1;
            static_queries[i].clear();
            dp[i]={0,0};
        }
    }
    for(int i=0;i<n;i++)
    {
        val_ends[b[i]].push_back({i,0});
        val_ends[a[i]].push_back({i,1});
        val_ends[c[i]].push_back({i,2});
    }
    vector<counter> cnt(n);
    vector<summer> sum((n-1)/N+1);
    vector<array<int,3>> in(n,{0,0,0});
    auto flip=[&](int p,int t)
    {
        in[p][t]^=1;
        int l=(p/N)*N;
        int r=min(n,l+N);
        counter now;
        for(int i=l;i<r;i++)
        {
            if(in[i][2]) now.add_z();
            if(in[i][1]) now.add_y();
            if(in[i][0]) now.add_x();
            cnt[i]=now;
        }
        for(int bucket=(p/N);bucket*N<n;bucket++)
        {
            sum[bucket]=(bucket==0?summer():sum[bucket-1]);
            sum[bucket].add_counter(cnt[min(n-1,(bucket+1)*N-1)]);
        }
    };
    for(int i=0;i<n;i++)
    {
        for(auto [p,t]:val_starts[i]) flip(p,t);
        int idx=0;
        int sz=val_changes[i].size();
        for(int ql:dynamic_queries[i])
        {
            int qr=min(q,ql+Q);
            for(int o=ql;o<qr;o++)
            {
                if(tp[o]==1) continue;
                while(idx<sz)
                {
                    auto [ot,p,t]=val_changes[i][idx];
                    if(ot>o) break;
                    flip(p,t);
                    idx++;
                }
                int r=queries[o][0];
                summer now;
                if((r/N)-1>=0) now=sum[(r/N)-1];
                now.add_counter(cnt[r]);
                res[o]+=now.xyz;
            }
        }
        while(idx<sz)
        {
            auto [ot,p,t]=val_changes[i][idx++];
            if(ot<q) flip(p,t);
        }
        for(auto [p,t]:val_ends[i]) flip(p,t);
    }
    for(int o=0;o<q;o++) if(tp[o]==2) cout << res[o] << "\n";
    return 0;
}