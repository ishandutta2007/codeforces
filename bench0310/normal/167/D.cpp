#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Treap;
using twoTreaps=array<Treap*,2>;

struct Treap
{
    int x;
    int y;
    array<int,2> dp;
    twoTreaps kids;
    Treap(int a,int b){x=a;y=b;dp={0,0};kids[0]=kids[1]=nullptr;}
};

void recalc(Treap *me)
{
    me->dp={0,0};
    for(Treap *to:me->kids) if(to) me->dp[0]+=max(to->dp[0],to->dp[1]);
    if(me->kids[0]&&me->kids[1])
    {
        for(int i=0;i<=1;i++) me->dp[1]=max(me->dp[1],me->kids[i]->dp[0]+1+max(me->kids[1-i]->dp[0],me->kids[1-i]->dp[1]));
    }
    else if(me->kids[0]) me->dp[1]=me->kids[0]->dp[0]+1;
    else if(me->kids[1]) me->dp[1]=me->kids[1]->dp[0]+1;
}

twoTreaps splitval(Treap *me,int val)
{
    if(!me) return {nullptr,nullptr};
    if(me->x>val)
    {
        twoTreaps res=splitval(me->kids[0],val);
        me->kids[0]=res[1];
        recalc(me);
        return {res[0],me};
    }
    else
    {
        twoTreaps res=splitval(me->kids[1],val);
        me->kids[1]=res[0];
        recalc(me);
        return {me,res[1]};
    }
}

Treap* tmerge(Treap *a,Treap *b)
{
    if(!a) return b;
    if(!b) return a;
    if(a->y>b->y)
    {
        a->kids[1]=tmerge(a->kids[1],b);
        recalc(a);
        return a;
    }
    else
    {
        b->kids[0]=tmerge(a,b->kids[0]);
        recalc(b);
        return b;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vector<ll> x(n+1,0);
    vector<ll> y(n+1,0);
    for(int i=1;i<=k;i++) cin >> x[i] >> y[i];
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    const ll mod=1000000009;
    for(int i=k+1;i<=n;i++)
    {
        x[i]=(a*x[i-1]+b)%mod;
        y[i]=(c*y[i-1]+d)%mod;
    }
    vector<array<ll,2>> v(n);
    for(int i=1;i<=n;i++) v[i-1]={x[i],y[i]};
    sort(v.begin(),v.end());
    Treap *root=new Treap(v[0][0],v[0][1]);
    for(int i=1;i<n;i++) root=tmerge(root,new Treap(v[i][0],v[i][1]));
    int m;
    cin >> m;
    while(m--)
    {
        int l,r;
        cin >> l >> r;
        auto [one,tmp]=splitval(root,l-1);
        auto [two,three]=splitval(tmp,r);
        cout << (two?max(two->dp[0],two->dp[1]):0) << "\n";
        root=tmerge(tmerge(one,two),three);
    }
    return 0;
}