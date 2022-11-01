#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll inf=(1ll<<60);

struct Node
{
    ll val;
    ll lazy;
    int sz;
    Node *l,*r;
    Node(){val=inf;lazy=0;sz=0;l=r=nullptr;}
    void recalc()
    {
        val=inf;
        sz=0;
        if(l)
        {
            val=min(val,l->val);
            sz+=l->sz;
        }
        if(r)
        {
            val=min(val,r->val);
            sz+=r->sz;
        }
    }
    void apply(ll x)
    {
        val=min(val+x,inf);
        lazy+=x;
    }
    void push()
    {
        if(lazy>0)
        {
            if(l)
            {
                l->val+=lazy;
                l->lazy+=lazy;
            }
            if(r)
            {
                r->val+=lazy;
                r->lazy+=lazy;
            }
            lazy=0;
        }
    }
};

void update(Node *now,int l,int r,int pos,ll val)
{
    if(l==r)
    {
        now->val=val;
        now->sz=1;
    }
    else
    {
        int m=(l+r)/2;
        now->push();
        if(pos<=m)
        {
            if(!now->l) now->l=new Node();
            update(now->l,l,m,pos,val);
        }
        else
        {
            if(!now->r) now->r=new Node();
            update(now->r,m+1,r,pos,val);
        }
        now->recalc();
    }
}

ll query(Node *now,int l,int r,int pos)
{
    if(!now) return inf;
    if(l==r) return now->val;
    int m=(l+r)/2;
    now->push();
    if(pos<=m) return query(now->l,l,m,pos);
    else return query(now->r,m+1,r,pos);
}

void tmerge(Node *one,Node *two,int l,int r)
{
    if(l==r)
    {
        one->val=min(one->val,two->val);
        one->sz=1;
    }
    else
    {
        int m=(l+r)/2;
        one->push();
        two->push();
        if(two->l)
        {
            if(!one->l) one->l=two->l;
            else tmerge(one->l,two->l,l,m);
        }
        if(two->r)
        {
            if(!one->r) one->r=two->r;
            else tmerge(one->r,two->r,m+1,r);
        }
        one->recalc();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=200000;
    int n,s;
    cin >> n >> s;
    function<Node*(int,ll)> solve=[&](int pos,ll x)
    {
        Node *root=new Node();
        update(root,0,N,pos,x);
        while(n)
        {
            n--;
            string tp;
            cin >> tp;
            if(tp=="set")
            {
                int a;
                ll b;
                cin >> a >> b;
                ll temp=root->val;
                root->apply(b);
                if(a!=s) update(root,0,N,a,temp);
            }
            else if(tp=="if")
            {
                int a;
                cin >> a;
                Node *nxt=solve(a,query(root,0,N,a));
                update(root,0,N,a,inf);
                if(root->sz<nxt->sz) swap(root,nxt);
                tmerge(root,nxt,0,N);
            }
            else if(tp=="end") break;
        }
        return root;
    };
    cout << solve(0,0)->val << "\n";
    return 0;
}