#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct obj
{
    int one=0,two=0,three=0;
    int best=0;
    array<int,3> lazy={0,0,0};
    void pull(obj &l,obj &r)
    {
        one=min(l.one,r.one);
        two=min(l.two,r.two);
        three=min(l.three,r.three);
        best=min({l.best,r.best,l.one+r.two});
    }
    void apply(array<int,3> t)
    {
        auto [a,b,c]=t;
        auto &[la,lb,lc]=lazy;
        one+=a; one-=b;
        two+=b; two-=c;
        three+=a; three-=c;
        best+=a; best-=c;
        la+=a; lb+=b; lc+=c;
    }
    void push(obj &l,obj &r)
    {
        l.apply(lazy);
        r.apply(lazy);
        lazy={0,0,0};
    }
};

const int N=100005;
vector<obj> tree(4*N);

void pull(int idx){tree[idx].pull(tree[2*idx],tree[2*idx+1]);}
void apply(int idx,array<int,3> t){tree[idx].apply(t);}
void push(int idx){tree[idx].push(tree[2*idx],tree[2*idx+1]);}

void update(int idx,int l,int r,int ql,int qr,array<int,3> t)
{
    if(ql>qr) return;
    if(l==ql&&r==qr) apply(idx,t);
    else
    {
        int m=(l+r)/2;
        push(idx);
        update(2*idx,l,m,ql,min(qr,m),t);
        update(2*idx+1,m+1,r,max(ql,m+1),qr,t);
        pull(idx);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    s="$"+s;
    array<int,3> c={0,0,0};
    for(int i=1;i<=n;i++)
    {
        c[s[i]-'a']++;
        update(1,0,n,i,i,c);
    }
    auto val=[&](char a,int d)->array<int,3>
    {
        array<int,3> t={0,0,0};
        t[a-'a']=d;
        return t;
    };
    int cnt=c[2];
    while(q--)
    {
        int p;
        char a;
        cin >> p >> a;
        cnt-=(s[p]=='c');
        update(1,0,n,p,n,val(s[p],-1));
        s[p]=a;
        cnt+=(s[p]=='c');
        update(1,0,n,p,n,val(s[p],1));
        cout << cnt+min(tree[1].best,tree[1].three) << "\n";
    }
    return 0;
}