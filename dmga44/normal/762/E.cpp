#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define MAXN (int)(6e5+5)

vector<int> priorities;
int prio_pos;

struct node
{
    int prior;
    int sum;
    int key;
    node *l,*r;
    node(int kk) : key(kk),l(0),r(0)
    {
        sum=1;
        prior=priorities[prio_pos];
        prio_pos++;
    }
};
typedef node* pnode;

struct treap
{
    pnode root;

    treap() : root(0){}

    int sum(pnode t)
    {
        return t ? t->sum : 0;
    }

    void update_sum(pnode t)
    {
        if(t)
            t->sum=1+sum(t->l)+sum(t->r);
    }

    void split(pnode p,int key,pnode &l,pnode &r)
    {
        if(!p)
            l=r=0;
        else if(key<p->key)
        {
            split(p->l,key,l,p->l);
            r=p;
        }
        else
        {
            split(p->r,key,p->r,r);
            l=p;
        }
        update_sum(p);
    }

    void insert(pnode &p,pnode it)
    {
        if(!p)
            p=it;
        else if(it->prior>p->prior)
        {
            split(p,it->key,it->l,it->r);
            p=it;
        }
        else
        {
            if(it->key<p->key)
                insert(p->l,it);
            else
                insert(p->r,it);
        }
        update_sum(p);
    }

    void merge(pnode &p,pnode l,pnode r)
    {
        if(!l || !r)
        {
            if(l)
                p=l;
            else
                p=r;
        }
        else if(l->prior>r->prior)
        {
            merge(l->r,l->r,r);
            p=l;
        }
        else
        {
            merge(r->l,l,r->l);
            p=r;
        }
        update_sum(p);
    }

    void erase(pnode &p,int key)
    {
        if(p->key==key)
            merge(p,p->l,p->r);
        else if(key<p->key)
            erase(p->l,key);
        else
            erase(p->r,key);
        update_sum(p);
    }
};

treap a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    mt19937 rng(time(0));
    for(int i=0;i<MAXN;i++)
        priorities.push_back(i);
    shuffle(all(priorities),rng);

    int n,k,x,r,f;
    cin >> n >> k;
    vector<pip> vp;
    for(int i=0;i<n;i++)
    {
        cin >> x >> r >> f;
        vp.push_back(pip(r,pii(f,x)));
    }

    sort(allr(vp));

    ll res=0;
    for(int i=0;i<n;i++)
    {
        r=vp[i].f;
        f=vp[i].s.f;
        x=vp[i].s.s;
        for(int j=max(f-k,0);j<=f+k;j++)
        {
            pnode l1,r1;
            a[j].split(a[j].root,x-r-1,l1,r1);
            pnode l2,r2;
            a[j].split(r1,x+r,l2,r2);
//            if(a[j].sum(l2))
//                cout << r << ' ' << f << ' ' << x << ' ' << j << '\n';
            res+=a[j].sum(l2);
            a[j].merge(r1,l2,r2);
            a[j].merge(a[j].root,l1,r1);
        }

        pnode add=new node(x);
        a[f].insert(a[f].root,add);
    }
    db(res)

    return 0;
}
/**
3 2
1 3 10
3 2 5
4 10 8

5 1
1 3 2
2 2 4
3 2 1
4 2 1
5 3 3
**/