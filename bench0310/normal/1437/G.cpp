#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
typedef long long ll;

const int N=300005;
vector<int> sus(N,0);
vector<vector<int>> trie(N,vector<int>(26,-1));
int tidx=1;
multiset<int> opt[N];
vector<int> best(N,-1);

int add(string s)
{
    int now=0;
    //cout << "adding " << s << endl;
    for(char c:s)
    {
        if(trie[now][c-'a']==-1) trie[now][c-'a']=tidx++;
        now=trie[now][c-'a'];
        //cout << now << "->";
    }
    //cout << endl;
    return now;
}

int qry(string s)
{
    //cout << "descend " << s << endl;
    int now=0;
    int res=-1;
    for(char c:s)
    {
        if(trie[now][c-'a']==-1) break;
        now=trie[now][c-'a'];
        //cout << "reached " << now << "with sus=" << best[now] << endl;
        res=max(res,best[now]);
    }
    //cout << endl;
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
    auto rng=[&](int l,int r)->int{return uniform_int_distribution<int>(l,r)(gen);};
    const ll p=33;
    const ll mod=rng(100000000,2000000000);
    vector<ll> pw(N,1);
    for(int i=1;i<N;i++) pw[i]=(pw[i-1]*p)%mod;
    int n,m;
    cin >> n >> m;
    auto geth=[&](string &s)->ll
    {
        ll h=0;
        for(char c:s) h=(p*h+(c-'a'+1))%mod;
        return h;
    };
    const int sz=200;
    vector<string> names(n+1);
    vector<int> big;
    vector<int> h(n+1,0);
    vector<int> tid(n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> names[i];
        if(names[i].size()>=sz)
        {
            h[i]=geth(names[i]);
            big.push_back(i);
        }
        else
        {
            tid[i]=add(names[i]);
            opt[tid[i]].insert(0);
            best[tid[i]]=0;
        }
    }
    while(m--)
    {
        int t;
        cin >> t;
        if(t==1)
        {
            int i,x;
            cin >> i >> x;
            if(names[i].size()<sz)
            {
                opt[tid[i]].erase(opt[tid[i]].find(sus[i]));
                opt[tid[i]].insert(x);
                best[tid[i]]=(*opt[tid[i]].rbegin());
            }
            sus[i]=x;
        }
        else
        {
            string z;
            cin >> z;
            int len=z.size();
            vector<ll> now(len,0);
            now[0]=(z[0]-'a'+1);
            for(int i=1;i<len;i++) now[i]=(now[i-1]*p+(z[i]-'a'+1))%mod;
            auto val=[&](int l,int r)->int
            {
                ll x=now[r];
                ll y=(l>0?now[l-1]:0);
                ll res=(x-pw[r-l+1]*y)%mod;
                if(res<0) res+=mod;
                return res;
            };
            int res=-1;
            for(int i=0;i<len;i++) res=max(res,qry(z.substr(i,sz-1)));
            for(int b:big)
            {
                int req=names[b].size();
                int hs=h[b];
                for(int i=0;i+req-1<len;i++)
                {
                    ll x=val(i,i+req-1);
                    if(x==hs) res=max(res,sus[b]);
                }
            }
            cout << res << "\n";
        }
    }
    return 0;
}