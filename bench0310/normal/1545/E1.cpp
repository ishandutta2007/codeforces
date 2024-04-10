#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());

struct Tag
{
    ll x; //-1 when none
    int tp; //l|r
    Tag(){x=-1;tp=0;}
    Tag(ll nx,int ntp){x=nx;tp=ntp;}
    void set(ll nx,int ntp){x=nx;tp=ntp;}
    bool empty(){return (x==-1);}
    void reset(){x=-1;}
    tuple<Tag,ll,Tag> push(int szl,int szr)
    {
        tuple<Tag,ll,Tag> r;
        if(tp==0) r={Tag(x,0),x+szl,Tag(x+szl+1,0)};
        else r={Tag(x+szr+1,1),x+szr,Tag(x,1)};
        reset();
        return r;
    }
};

struct Treap;
using twoTreaps=array<Treap*,2>;

struct Treap
{
    ll val;
    Tag lazy;
    int sz;
    int priority;
    twoTreaps kids;
    Treap(ll nval){val=nval;lazy=Tag();sz=1;priority=gen();kids[0]=kids[1]=nullptr;}
};

int sz(Treap *me){return (me?me->sz:0);}

void recalc(Treap *me)
{
    if(!me) return;
    me->sz=1;
    for(Treap *to:me->kids) me->sz+=sz(to);
}

void apply(Treap *me,ll x,int tp){if(me) me->lazy.set(x,tp);}

void push(Treap *me)
{
    if(!me||me->lazy.empty()) return;
    auto [lazyl,nval,lazyr]=me->lazy.push(sz(me->kids[0]),sz(me->kids[1]));
    me->val=nval;
    if(me->kids[0]) me->kids[0]->lazy=lazyl;
    if(me->kids[1]) me->kids[1]->lazy=lazyr;
}

twoTreaps tsplit(Treap *me,int cnt)
{
    if(!me) return {nullptr,nullptr};
    push(me);
    if(sz(me->kids[0])>=cnt)
    {
        twoTreaps res=tsplit(me->kids[0],cnt);
        me->kids[0]=res[1];
        recalc(me);
        return {res[0],me};
    }
    else
    {
        twoTreaps res=tsplit(me->kids[1],cnt-sz(me->kids[0])-1);
        me->kids[1]=res[0];
        recalc(me);
        return {me,res[1]};
    }
}

Treap* tmerge(Treap *a,Treap *b)
{
    if(!a) return b;
    if(!b) return a;
    push(a);
    push(b);
    if(a->priority<b->priority)
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

ll get_left(Treap *me){push(me); return (me->kids[0]?get_left(me->kids[0]):me->val);}
ll get_right(Treap *me){push(me); return (me->kids[1]?get_right(me->kids[1]):me->val);}

Treap* advance_time(Treap *me,ll t)
{
    int s=sz(me);
    ll l=get_left(me);
    if(t<s)
    {
        int keep=s-t;
        auto [one,two]=tsplit(me,keep);
        apply(two,l+1,1);
        return tmerge(two,one);
    }
    else
    {
        apply(me,l+t-sz(me)+1,1);
        return me;
    }
}

int find_cnt_left(Treap *me,ll x)
{
    if(!me) return 0;
    push(me);
    if(x+sz(me->kids[0])<me->val) return sz(me->kids[0])+1+find_cnt_left(me->kids[1],x+sz(me->kids[0])+1);
    else return find_cnt_left(me->kids[0],x);
}

int find_cnt_right(Treap *me,ll x)
{
    if(!me) return 0;
    push(me);
    if(x+sz(me->kids[1])<me->val) return sz(me->kids[1])+1+find_cnt_right(me->kids[0],x+sz(me->kids[1])+1);
    else return find_cnt_right(me->kids[1],x);
}

Treap* merge_segments(Treap *l,Treap *m,Treap *r)
{
    if(!l) apply(m,get_left(r)+1,1);
    else if(!r) apply(m,get_right(l)+1,0);
    else
    {
        int s=sz(m);
        ll x=get_right(l);
        ll y=get_left(r);
        if(x+s+1<y)
        {
            apply(m,x+1,0);
            int cnt=find_cnt_left(r,x+s+1);
            auto [one,two]=tsplit(r,cnt);
            apply(one,x+s+1,0);
            r=tmerge(one,two);
        }
        else if(y+s+1<x)
        {
            apply(m,y+1,1);
            int cnt=sz(l)-find_cnt_right(l,y+s+1);
            auto [one,two]=tsplit(l,cnt);
            apply(two,y+s+1,1);
            l=tmerge(one,two);
        }
        else
        {
            int cnt=(y-x+s+1)/2;
            auto [one,two]=tsplit(m,cnt);
            apply(one,x+1,0);
            apply(two,y+1,1);
            m=tmerge(one,two);
        }
    }
    return tmerge(tmerge(l,m),r);
}

ll get_min(Treap *me)
{
    push(me);
    ll r=(me->val);
    for(Treap *to:me->kids) if(to) r=min(r,get_min(to));
    return r;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    //set up segments
    int n,ini_pos;
    cin >> n >> ini_pos;
    const int lim=2000002;
    map<array<int,2>,pair<Treap*,int>> active;
    Treap *ini=nullptr;
    for(int i=0;i<=lim;i++) ini=tmerge(ini,new Treap(abs(ini_pos-i)));
    active[{0,lim}]={ini,0};
    map<array<int,2>,Treap*> blocked;
    blocked[{-1,-1}]=blocked[{lim+1,lim+1}]=nullptr;
    //set up events
    vector<array<int,2>> events_block[lim];
    vector<array<int,2>> events_unblock[lim];
    int events_mx=0;
    for(int i=1;i<=n;i++)
    {
        int tl,tr,l,r;
        cin >> tl >> tr >> l >> r;
        events_block[tl].push_back({l,r});
        events_unblock[tr+1].push_back({l,r});
        events_mx=max(events_mx,tr+1);
    }
    //go
    multiset<array<int,2>> blockers_l,blockers_r;
    blockers_l.insert({lim+1,lim+1});
    auto add_blocker=[&](int l,int r,int t)
    {
        blockers_l.insert({l,r});
        blockers_r.insert({r,l});
        while(1)
        {
            auto it=active.lower_bound({r+1,0});
            it--;
            auto [sl,sr]=it->first;
            if(sr<l) break;
            auto [me,prv_t]=it->second;
            advance_time(me,t-prv_t);
            active.erase(it);
            if(l<=sl&&sr<=r) blocked[{sl,sr}]=me;
            else if(sl<l&&r<sr)
            {
                auto [one,tmp]=tsplit(me,l-sl);
                auto [two,three]=tsplit(tmp,r-l+1);
                active[{sl,l-1}]={one,t};
                blocked[{l,r}]=two;
                active[{r+1,sr}]={three,t};
            }
            else if(sl<l)
            {
                auto [one,two]=tsplit(me,l-sl);
                active[{sl,l-1}]={one,t};
                blocked[{l,sr}]=two;
            }
            else if(r<sr)
            {
                auto [one,two]=tsplit(me,sr-sl+1-(sr-r));
                active[{r+1,sr}]={two,t};
                blocked[{sl,r}]=one;
            }
        }
    };
    auto blocked_add_cut=[&](int l)
    {
        auto it=blocked.lower_bound({l+1,0});
        if(it==blocked.begin()) return;
        it--;
        auto [sl,sr]=it->first;
        if(!(sl<=l&&l<=sr)) return;
        Treap *me=it->second;
        blocked.erase(it);
        auto [one,two]=tsplit(me,l-sl+1);
        if(sl<=l) blocked[{sl,l}]=one;
        if(l+1<=sr) blocked[{l+1,sr}]=two;
    };
    auto collect_blocked_range=[&](int l,int r)->Treap*
    {
        blocked_add_cut(l-1);
        blocked_add_cut(r);
        Treap *me=nullptr;
        while(1)
        {
            auto it=blocked.lower_bound({l,0});
            auto [sl,sr]=it->first;
            if(r<sl) break;
            assert(sr<=r);
            Treap *t=it->second;
            blocked.erase(it);
            me=tmerge(me,t);
        }
        return me;
    };
    auto rm_blocker=[&](int l,int r,int t)
    {
        blockers_l.erase(blockers_l.find({l,r}));
        blockers_r.erase(blockers_r.find({r,l}));
        auto it=active.lower_bound({l,0});
        it--;
        auto [pl,pr]=it->first;
        auto [pt,pprv_t]=it->second;
        advance_time(pt,t-pprv_t);
        active.erase(it);
        it=active.lower_bound({r+1,0});
        auto [nl,nr]=it->first;
        auto [nt,nprv_t]=it->second;
        advance_time(nt,t-nprv_t);
        active.erase(it);
        auto it2=blockers_l.lower_bound({pr+1,0});
        if((*it2)[0]>nr)
        {
            Treap *m=collect_blocked_range(pr+1,nl-1);
            active[{pl,nr}]={merge_segments(pt,m,nt),t};
        }
        else
        {
            //check left
            int tr=(*it2)[0]-1;
            active[{pl,tr}]={merge_segments(pt,collect_blocked_range(pr+1,tr),nullptr),t};
            //check right
            auto it3=blockers_r.lower_bound({nl,0});
            it3--;
            int tl=(*it3)[0]+1;
            active[{tl,nr}]={merge_segments(nullptr,collect_blocked_range(tl,nl-1),nt),t};
        }
    };
    for(int t=0;t<=events_mx;t++)
    {
        for(auto [l,r]:events_block[t]) add_blocker(l,r,t);
        for(auto [l,r]:events_unblock[t]) rm_blocker(l,r,t);
        for(auto bad:events_block[t+1]) //cut here to prevent corner jumping
        {
            int r=bad[1];
            auto it=active.lower_bound({r+1,0});
            if(it==active.begin()) continue;
            it--;
            auto [sl,sr]=it->first;
            if(!(sl<=r&&r<sr)) continue;
            auto [me,prv_t]=it->second;
            active.erase(it);
            advance_time(me,t-prv_t);
            auto [one,two]=tsplit(me,r-sl+1);
            active[{sl,r}]={one,t};
            active[{r+1,sr}]={two,t};
        }
    }
    assert(active.size()==1);
    auto [me,prv_t]=active.begin()->second;
    advance_time(me,events_mx+1-prv_t);
    cout << get_min(me) << "\n";
    return 0;
}