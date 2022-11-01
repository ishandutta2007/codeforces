#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=400005;
const int mod=1000000007;
int add(int a,int b){return a+b-(a+b>=mod?mod:0);}
int sub(int a,int b){return a-b+(a-b<0?mod:0);}
vector<int> tree(4*N,0);

void update(int idx,int l,int r,int pos,int val)
{
    if(l==r) tree[idx]=add(tree[idx],val);
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,val);
        else update(2*idx+1,m+1,r,pos,val);
        tree[idx]=add(tree[2*idx],tree[2*idx+1]);
    }
}

int query(int idx,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return tree[idx];
    int m=(l+r)/2;
    return add(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    vector<int> b(n+1,0);
    vector<int> hb(2*n+1,0);
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] >> b[i];
        hb[b[i]]=i;
    }
    auto upd=[&](int pos,int val){update(1,1,2*n,pos,val);};
    auto qry=[&](int ql,int qr)->int{return query(1,1,2*n,ql,qr);};
    vector<int> cost(n+1,0);
    for(int i=1;i<=2*n;i++)
    {
        int x=hb[i];
        if(x==0) continue;
        cost[x]=add(1,qry(a[x],b[x]));
        upd(a[x],cost[x]);
    }
    int res=0;
    int lim=2*n;
    int t;
    cin >> t;
    vector<int> v(t);
    for(int i=0;i<t;i++) cin >> v[i];
    sort(v.begin(),v.end(),[&](int x,int y){return (b[x]<b[y]);});
    auto mv=[&](int nb)
    {
        while(nb<=lim)
        {
            int x=hb[lim];
            if(x!=0) upd(a[x],sub(0,cost[x]));
            lim--;
        }
    };
    function<void(int)> go=[&](int l)
    {
        while(!v.empty()&&a[v.back()]<l) v.pop_back();
        if(v.empty()||b[v.back()]<l) return;
        int x=v.back();
        v.pop_back();
        mv(b[x]);
        res=add(res,qry(l,b[x]));
        res=add(res,1);
        go(a[x]);
    };
    go(1);
    cout << res << "\n";
    return 0;
}