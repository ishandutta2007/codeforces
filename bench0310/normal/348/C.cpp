#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=100005;
    const int sz=316;
    const int lim=(N/sz); //max number of big sets
    int n,m,q;
    cin >> n >> m >> q;
    vector<ll> tmp(n+1,0);
    vector<ll> ini(m+1,0);
    for(int i=1;i<=n;i++) cin >> tmp[i];
    vector<bool> is_big(m+1,0);
    vector<int> big;
    vector<int> big_id(m+1,0);
    bitset<N> sets[lim+1];
    vector<vector<int>> v(m+1);
    int id=1;
    vector<int> one[n+1];
    for(int i=1;i<=m;i++)
    {
        int c;
        cin >> c;
        v[i].assign(c,0);
        for(int j=0;j<c;j++) cin >> v[i][j];
        for(int a:v[i]) ini[i]+=tmp[a];
        if(c>=sz)
        {
            is_big[i]=1;
            big_id[i]=id++;
            big.push_back(i);
            for(int a:v[i])
            {
                sets[big_id[i]][a]=1;
                one[a].push_back(big_id[i]);
            }
        }
    }
    vector<vector<int>> two_big(lim+1,vector<int>(lim+1));
    for(int i=1;i<=n;i++) for(int a:one[i]) for(int b:one[i]) two_big[a][b]++;
    vector<ll> d(n+1,0);
    auto isz=[&](int a,int b)->int
    {
        assert(is_big[a]||is_big[b]);
        if(is_big[a]==1&&is_big[b]==1) return two_big[big_id[a]][big_id[b]];
        if(is_big[a]==0) swap(a,b);
        int res=0;
        for(int x:v[b]) res+=sets[big_id[a]][x];
        return res;
    };
    vector<ll> val(lim+1,0);
    while(q--)
    {
        char t;
        int k;
        cin >> t >> k;
        if(t=='?')
        {
            ll res=ini[k];
            if(is_big[k]==1)
            {
                for(int b:big) res+=(val[big_id[b]]*isz(k,b));
            }
            else
            {
                for(int a:v[k]) res+=d[a];
                for(int b:big) res+=(val[big_id[b]]*isz(k,b));
            }
            cout << res << "\n";
        }
        else if(t=='+')
        {
            ll num=0;
            cin >> num;
            if(is_big[k]==1) val[big_id[k]]+=num;
            else
            {
                for(int a:v[k]) d[a]+=num;
                for(int b:big) ini[b]+=(num*isz(k,b));
            }
        }
    }
    return 0;
}