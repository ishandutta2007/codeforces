#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct node
{
    ll sum;
    int lazy;
    int lvl;
    node *l,*r;
    node(ll x){sum=x;lazy=0;lvl=0;l=nullptr;r=nullptr;}
    node(node *a,node *b){sum=a->sum+b->sum;lazy=0;lvl=a->lvl+1;l=a;r=b;}
};

vector<ll> val((1<<18)+1,0);

node* build(int idx,int l,int r)
{
    if(l==r) return new node(val[l]);
    else
    {
        int m=(l+r)/2;
        return new node(build(2*idx,l,m),build(2*idx+1,m+1,r));
    }
}

void push(node *a)
{
    if(a->lazy&(1<<a->lvl)) swap(a->l,a->r);
    a->lazy&=((1<<a->lvl)-1);
    a->l->lazy^=a->lazy;
    a->r->lazy^=a->lazy;
    a->lazy=0;
}

void update(node *a,int l,int r,int pos,ll x)
{
    if(l==r) a->sum=x;
    else
    {
        push(a);
        int m=(l+r)/2;
        if(pos<=m) update(a->l,l,m,pos,x);
        else update(a->r,m+1,r,pos,x);
        a->sum=a->l->sum+a->r->sum;
    }
}

ll query(node *a,int l,int r,int ql,int qr)
{
    if(ql>qr) return 0;
    if(l==ql&&r==qr) return a->sum;
    push(a);
    int m=(l+r)/2;
    return query(a->l,l,m,ql,min(qr,m))+query(a->r,m+1,r,max(ql,m+1),qr);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=(1<<n);i++) cin >> val[i];
    node *root=build(1,1,(1<<n));
    while(q--)
    {
        int t,a,b;
        cin >> t >> a;
        if(t==1||t==4) cin >> b;
        if(t==1) update(root,1,(1<<n),a,b);
        else if(t==2) root->lazy^=((1<<(a+1))-1);
        else if(t==3) root->lazy^=(1<<(a+1));
        else cout << query(root,1,(1<<n),a,b) << "\n";
    }
    return 0;
}