#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Node
{
    ll val;
    ll lazy;
    Node *l,*r;
    Node(){val=lazy=0;l=r=nullptr;}
    void recalc(){val=l->val+r->val;}
    void push(int a,int b,int m)
    {
        if(l==nullptr) l=new Node();
        if(r==nullptr) r=new Node();
        l->val+=(lazy*(m-a+1));
        r->val+=(lazy*(b-m));
        l->lazy+=lazy;
        r->lazy+=lazy;
        lazy=0;
    }
};

void update(Node *now,int l,int r,int ql,int qr,ll x)
{
    if(ql>qr) return;
    if(l==ql&&r==qr)
    {
        now->val+=(x*(r-l+1));
        now->lazy+=x;
    }
    else
    {
        int m=(ll(l)+r)/2;
        now->push(l,r,m);
        update(now->l,l,m,ql,min(qr,m),x);
        update(now->r,m+1,r,max(ql,m+1),qr,x);
        now->recalc();
    }
    
}

int mn(Node *now,int l,int r)
{
    if(l==r) return l;
    int m=(ll(l)+r)/2;
    now->push(l,r,m);
    if(now->l->val>0) return mn(now->l,l,m);
    else return mn(now->r,m+1,r);
}

int go(Node *now,int l,int r,int k)
{
    if(l==r) return l;
    int m=(ll(l)+r)/2;
    now->push(l,r,m);
    if(now->l->val>=k) return go(now->l,l,m,k);
    else return go(now->r,m+1,r,k-now->l->val);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=2000000000;
    Node *root=new Node();
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end(),greater<int>());
    int res=N+1;
    update(root,0,N,0,0,1);
    for(int l:v)
    {
        int d=mn(root,0,N);
        update(root,0,N,d,d,-1);
        int one=l/2;
        int two=l-one-1;
        update(root,0,N,d+2,d+2+one-1,1);
        update(root,0,N,d+2,d+2+two-1,1);
        if(root->val>=k) res=min(res,go(root,0,N,k));
    }
    if(res==N+1) res=-1;
    cout << res << "\n";
    return 0;
}