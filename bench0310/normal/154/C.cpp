#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    const int mod_one=uniform_int_distribution<int>(100000000,1000000000)(rng);
    const int mod_two=uniform_int_distribution<int>(100000000,1000000000)(rng);
    vector<int> p_one(n+1,1);
    for(int i=1;i<=n;i++) p_one[i]=(2*p_one[i-1])%mod_one;
    vector<int> p_two(n+1,1);
    for(int i=1;i<=n;i++) p_two[i]=(2*p_two[i-1])%mod_two;
    vector<int> h_one(n+1,0);
    vector<int> h_two(n+1,0);
    auto add=[&](int a,int b)->void
    {
        h_one[a]=(h_one[a]+p_one[b])%mod_one;
        h_two[a]=(h_two[a]+p_two[b])%mod_two;
    };
    auto rm=[&](int a,int b)->void
    {
        h_one[a]=(h_one[a]-p_one[b]+mod_one)%mod_one;
        h_two[a]=(h_two[a]-p_two[b]+mod_two)%mod_two;
    };
    vector<pair<int,int>> edges(m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
        edges[i]={a,b};
    }
    map<pair<int,int>,long long> t;
    for(int i=1;i<=n;i++) t[{h_one[i],h_two[i]}]++;
    long long res=0;
    for(auto [ignore,a]:t) res+=(a*(a-1)/2);
    for(auto [a,b]:edges)
    {
        rm(a,b);
        rm(b,a);
        res+=(h_one[a]==h_one[b]&&h_two[a]==h_two[b]);
        add(a,b);
        add(b,a);
    }
    printf("%I64d\n",res);
    return 0;
}