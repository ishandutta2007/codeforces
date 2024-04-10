#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

vector<int> st;
vector<int> res;

int sear(int p,int l)
{
    if(!st[p<<1] && !st[(p<<1)+1])
        return l;
    if(st[p<<1]>st[(p<<1)+1])
        return sear(p<<1,l+1);
    return sear((p<<1)+1,l+1);
}

void apply(int p)
{
    if(!st[p<<1] && !st[(p<<1)+1])
        st[p]=0;
    else if(st[p<<1]>st[(p<<1)+1])
    {
        st[p]=st[p<<1];
        apply(p<<1);
    }
    else
    {
        st[p]=st[(p<<1)+1];
        apply((p<<1)+1);
    }
}

void solve(int p,int l,int g)
{
    while(sear(p,l)!=g)
    {
        res.push_back(p);
        apply(p);
    }

    if(l==g)
        return ;
    if(st[p<<1])
        solve(p<<1,l+1,g);
    if(st[(p<<1)+1])
        solve((p<<1)+1,l+1,g);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int h,g;
        cin >> h >> g;
        st.resize((1<<(h+1)));
        for(int i=1;i<(1<<h);i++)
            cin >> st[i];

        solve(1,1,g);

        ll sum=0;
        for(int i=1;i<(1<<g);i++)
            sum+=st[i];
        db(sum)
        for(auto y : res)
            cout << y << ' ';
        cout << '\n';

        res.clear();
        st.clear();
    }

    return 0;
}
/**
2
3 2
7 6 3 5 4 2 1
3 2
7 6 5 4 3 2 1
**/