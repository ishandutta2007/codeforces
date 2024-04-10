#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
int rng(int l,int r){return uniform_int_distribution<int>(l,r)(gen);}

struct Treap;
using twoTreaps=array<Treap*,2>;

struct Treap
{
    int val;
    int sz;
    int priority;
    twoTreaps kids;
    Treap *p;
    Treap(int a){val=a;sz=1;priority=rng(1,(1<<30));kids[0]=kids[1]=p=nullptr;}
};

int sz(Treap *me){return (me?me->sz:0);}

void recalc(Treap *me)
{
    if(!me) return;
    me->sz=1;
    for(Treap *to:me->kids) me->sz+=sz(to);
}

void make_parent(Treap *me,int id,Treap *kid)
{
    if(me) me->kids[id]=kid;
    if(kid) kid->p=me;
    recalc(me);
}

twoTreaps split(Treap *me,int cnt)
{
    if(!me) return {nullptr,nullptr};
    if(sz(me->kids[0])>=cnt)
    {
        twoTreaps res=split(me->kids[0],cnt);
        if(me->kids[0]) me->kids[0]->p=nullptr;
        make_parent(me,0,res[1]);
        return {res[0],me};
    }
    else
    {
        twoTreaps res=split(me->kids[1],cnt-sz(me->kids[0])-1);
        if(me->kids[1]) me->kids[1]->p=nullptr;
        make_parent(me,1,res[0]);
        return {me,res[1]};
    }
}

Treap* tmerge(Treap *a,Treap *b)
{
    if(!a) return b;
    if(!b) return a;
    if(a->priority<b->priority)
    {
        make_parent(a,1,tmerge(a->kids[1],b));
        return a;
    }
    else
    {
        make_parent(b,0,tmerge(a,b->kids[0]));
        return b;
    }
}

int get_pos(Treap *me) //1-indexed
{
    int pos=1+sz(me->kids[0]);
    while(me->p)
    {
        Treap *p=me->p;
        if(p->kids[1]==me) pos+=(1+sz(p->kids[0]));
        me=p;
    }
    return pos;
}

int get_last(Treap *me)
{
    while(me->kids[1]) me=me->kids[1];
    return (me->val);
}

const int N=300005;
vector<int> v[N];
vector<int> x(N,0);
vector<int> mx(N,0);
vector<int> p(N,0);
vector<int> depth(N,0);
vector<int> sub(N,0);
vector<int> big(N,0);
vector<bool> fully_moved(N,0);
vector<Treap*> label(N,nullptr);
vector<int> chain_id(N,0);
vector<int> chain_of_label(N,0);
vector<int> chain_nodes[N];
vector<int> pos_in_chain(N,0);
vector<Treap*> chain(N,nullptr);
vector<int> head(N,0);
vector<int> head_of_chain(N,0);
vector<int> chain_res[N];

void dfs(int a)
{
    if(p[a]!=0) depth[a]=depth[p[a]]+1;
    sub[a]=1;
    for(int to:v[a])
    {
        dfs(to);
        sub[a]+=sub[to];
        if(sub[to]>sub[big[a]]) big[a]=to;
        mx[x[a]]=max(mx[x[a]],mx[x[to]]);
    }
    fully_moved[x[a]]=(mx[x[a]]<x[a]);
    mx[x[a]]=max(mx[x[a]],x[a]);
}

void out(){cout << "NO\n";exit(0);}

int one;
int req_now;

void dfs_check(int a)
{
    if(x[a]!=req_now++) out();
    sort(v[a].begin(),v[a].end(),[&](int b,int c){return (x[b]<x[c]);});
    for(int to:v[a])
    {
        if(x[to]<one) continue;
        dfs_check(to);
    }
}

int chain_now=0;

void decompose(int a,int ch,int hd)
{
    chain_id[a]=ch;
    chain_of_label[x[a]]=ch;
    head[a]=hd;
    head_of_chain[ch]=hd;
    chain_nodes[ch].push_back(a);
    pos_in_chain[a]=chain_nodes[ch].size();
    chain[ch]=tmerge(chain[ch],label[x[a]]);
    if(big[a]!=0) decompose(big[a],ch,hd);
    for(int to:v[a]) if(to!=big[a]) decompose(to,++chain_now,to);
}

void descend(Treap *me,int ch)
{
    if(!me) return;
    descend(me->kids[0],ch);
    chain_res[ch].push_back(me->val);
    descend(me->kids[1],ch);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //prepare
    int n;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> x[i];
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        p[b]=a;
    }
    dfs(1);
    one=1;
    while(one<n&&fully_moved[one]==1) one++;
    //bubble one
    int h=0;
    for(int i=1;i<=n;i++) if(x[i]==one) h=i;
    ll moves=0;
    for(int i=1;i<=n;i++) if(x[i]<=one) moves+=depth[i];
    int req_x=one+depth[h];
    while(h!=1)
    {
        if(x[p[h]]!=req_x) out();
        req_x--;
        swap(x[h],x[p[h]]);
        h=p[h];
    }
    vector<int> rev(n+1,0);
    for(int i=1;i<=n;i++) rev[x[i]]=i;
    //check if [one,n] is a dfs order
    req_now=one;
    dfs_check(1);
    //decompose hld-style, build chains
    for(int i=1;i<=n;i++) label[i]=new Treap(i);
    decompose(1,++chain_now,1);
    //bubble one-1 downTo 1
    for(int l=one-1;l>=1;l--)
    {
        int node=rev[l];
        vector<int> chains={chain_id[node]};
        while(head_of_chain[chains.back()]!=1) chains.push_back(chain_id[p[head_of_chain[chains.back()]]]);
        reverse(chains.begin(),chains.end());
        for(int i=(int)chains.size()-2;i>=0;i--)
        {
            int a=chains[i];
            int b=chains[i+1];
            auto [tmp1,tmp0]=split(chain[a],pos_in_chain[p[head_of_chain[b]]]-1);
            auto [tmp2,tmp3]=split(tmp0,1);
            chain[a]=tmerge(tmp1,tmp3);
            chain_of_label[tmp2->val]=b;
            chain[b]=tmerge(tmp2,chain[b]);
        }
        int pos=get_pos(label[l]);
        int c=chains.back();
        auto [tmp1,tmp0]=split(chain[c],pos-1);
        auto [tmp2,tmp3]=split(tmp0,1);
        if(get_last(tmp1)!=l+depth[node]) out();
        int to=chains[0];
        chain_of_label[l]=to;
        if(c!=to)
        {
            chain[to]=tmerge(tmp2,chain[to]);
            chain[c]=tmerge(tmp1,tmp3);
        }
        else chain[c]=tmerge(tmerge(tmp2,tmp1),tmp3);
    }
    //retrieve answer
    vector<int> res(n+1,0);
    for(int i=1;i<=chain_now;i++)
    {
        descend(chain[i],i);
        for(int j=0;j<(int)chain_nodes[i].size();j++) res[chain_nodes[i][j]]=chain_res[i][j];
    }
    cout << "YES\n";
    cout << moves << "\n";
    for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    return 0;
}