#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod=998244353;
int add(int a,int b){return a+b-(a+b>=mod?mod:0);}
int sub(int a,int b){return a-b+(a-b<0?mod:0);}
int mul(int a,int b){return (ll(a)*b)%mod;}

struct Tag
{
    int k,n;
    Tag(){clean();}
    Tag(int a,int b){k=a;n=b;}
    void apply(Tag t)
    {
        k=mul(k,t.k);
        n=add(mul(n,t.k),t.n);
    }
    void clean(){k=1;n=0;}
    int e(int x,int sz){return add(mul(k,x),mul(n,sz));}
};

struct Node
{
    int sum;
    Tag lazy;
    Node *l,*r;
    Node(){sum=0;l=r=nullptr;}
    void extend()
    {
        l=new Node();
        r=new Node();
    }
    void pull(){sum=add(l->sum,r->sum);}
    void apply(Tag t,int sz)
    {
        sum=t.e(sum,sz);
        lazy.apply(t);
    }
    void push(int one,int two)
    {
        if(!l) extend();
        l->apply(lazy,one);
        r->apply(lazy,two);
        lazy.clean();
    }
};

void update(Node *now,int l,int r,int ql,int qr,Tag t)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) now->apply(t,r-l+1);
    else
    {
        int m=(l+r)/2;
        now->push(m-l+1,r-(m+1)+1);
        update(now->l,l,m,ql,min(qr,m),t);
        update(now->r,m+1,r,max(ql,m+1),qr,t);
        now->pull();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    const int lim=1000000000;
    Node *root=new Node();
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        int sum=(i>1?(root->sum):1);
        update(root,1,lim,1,lim,Tag(mod-1,sum));
        update(root,1,lim,a+1,lim,Tag(0,0));
    }
    cout << (root->sum) << "\n";
    return 0;
}