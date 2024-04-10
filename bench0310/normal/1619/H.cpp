#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100000;
const int B=316;
struct bucket;

vector<bucket*> id(N+1,nullptr);

struct bucket
{
    vector<int> v;
    bucket *nxt=nullptr;
    bucket(){nxt=this;}
    bucket(vector<int> u)
    {
        for(int a:u)
        {
            v.push_back(a);
            id[a]=this;
        }
        nxt=this;
    }
    int sz(){return v.size();}
    void split()
    {
        vector<int> u;
        for(int i=0;i<B;i++) u.push_back(v[(int)v.size()-B+i]);
        for(int i=0;i<B;i++) v.pop_back();
        bucket *tmp=new bucket(u);
        tmp->nxt=nxt;
        nxt=tmp;
    }
    void meld()
    {
        for(int a:nxt->v)
        {
            v.push_back(a);
            id[a]=this;
        }
        bucket *tmp=nxt;
        nxt=nxt->nxt;
        delete tmp;
    }
    bool fix()
    {
        bool mv=0;
        while(sz()<B&&nxt!=this){meld();mv=1;}
        while(sz()>2*B){split();mv=1;}
        return mv;
    }
    void force(int a)
    {
        if(v.back()==a) return;
        bool ok=0;
        vector<int> u;
        for(int b:v)
        {
            if(ok) u.push_back(b);
            ok|=(b==a);
        }
        for(int i=0;i<(int)u.size();i++) v.pop_back();
        bucket *tmp=new bucket(u);
        tmp->nxt=nxt;
        nxt=tmp;
    }
    int query(int a,int p)
    {
        int pos=-1;
        for(int i=0;i<sz();i++)
        {
            if(v[i]==a)
            {
                pos=i;
                break;
            }
        }
        if(pos+p<sz()) return v[pos+p];
        return nxt->query(nxt->v[0],p-(sz()-pos));
    }
};

void checker(bucket *now)
{
    bucket *last_fix=now;
    do
    {
        if(now->fix()) last_fix=now;
        now=now->nxt;
    }while(last_fix!=now);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    vector<int> p(n+1,0);
    for(int i=1;i<=n;i++) cin >> p[i];
    for(int i=1;i<=n;i++)
    {
        if(id[i]!=nullptr) continue;
        vector<int> a={i};
        while(p[a.back()]!=i) a.push_back(p[a.back()]);
        bucket *tmp=new bucket(a);
        tmp->fix();
    }
    while(q--)
    {
        int t,x,y;
        cin >> t >> x >> y;
        if(t==1)
        {
            id[x]->force(x);
            bucket *one=id[x]->nxt;
            id[y]->force(y);
            bucket *two=id[y]->nxt;
            id[x]->nxt=two;
            id[y]->nxt=one;
            checker(id[x]);
            checker(id[y]);            
        }
        else cout << id[x]->query(x,y) << "\n";
    }
    return 0;
}