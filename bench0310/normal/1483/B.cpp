#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> tree;
int N;

void add(int idx,int d)
{
    for(;idx<N;idx=(idx|(idx+1))) tree[idx]+=d;
}

int sum(int r)
{
    int res=0;
    for(;r>=0;r=(r&(r+1))-1) res+=tree[r];
    return res;
}

int sum_t(int l,int r)
{
    return (sum(r)-sum(l-1));
}

int sum(int l,int r)
{
    if(l<=r) return sum_t(l,r);
    else return sum_t(l,N-1)+sum_t(1,r);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        N=n+1;
        tree.assign(N,0);
        for(int i=1;i<=n;i++) add(i,1);
        vector<int> ini(n+1,0);
        for(int i=1;i<=n;i++) cin >> ini[i];
        set<int> s;
        for(int i=1;i<=n;i++) s.insert(i);
        auto prv=[&](int a)->int
        {
            auto it=s.lower_bound(a);
            if(it!=s.begin())
            {
                it--;
                return (*it);
            }
            else return (*s.rbegin());
        };
        auto nxt=[&](int a)->int
        {
            auto it=s.upper_bound(a);
            if(it!=s.end()) return (*it);
            else return (*s.begin());
        };
        auto f=[&](int a,int b)->bool{return (gcd(ini[a],ini[b])==1);};
        set<int> opt;
        auto del=[&](int a)
        {
            int one=prv(a);
            int two=nxt(a);
            if(f(one,a)) opt.erase(one);
            if(f(a,two)) opt.erase(a);
            s.erase(a);
            if(one!=two&&f(one,two)) opt.insert(one);
            add(a,-1);
        };
        auto nxt_opt=[&](int a)->int
        {
            auto it=opt.lower_bound(a);
            if(it!=opt.end()) return (*it);
            else return (*opt.begin());
        };
        for(int i=1;i<=n;i++) if(f(i,nxt(i))) opt.insert(i);
        int song=1; //the last song you've listened to
        int now=1; //time
        vector<int> res(n+1,-1);
        vector<int> v;
        while(1)
        {
            if(opt.empty()) break;
            if(sum(1,n)<=1) break;
            int one=nxt_opt(song);
            int two=nxt(one);
            assert(f(one,two));
            now+=(sum(song,one)-1);
            now++;
            song=two;
            del(two);
            res[song]=now;
            v.push_back(song);
            song=nxt(song);
            now++;
        }
        if(ini[song]==1&&sum(1,n)==1)
        {
            res[song]=now+1;
            v.push_back(song);
        }
        cout << v.size();
        for(int a:v) cout << " " << a;
        cout << "\n";
    }
    return 0;
}