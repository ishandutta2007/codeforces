#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=500005;

struct ST
{
    int n,_n;
    vector<int> tree;
    ST(int hidx,int tn)
    {
        n=hidx;
        _n=tn;
        tree.assign(4*N,_n+1);
    }
    void update(int idx,int l,int r,int pos,int val)
    {
        if(l==r) tree[idx]=val;
        else
        {
            int m=(l+r)/2;
            if(pos<=m) update(2*idx,l,m,pos,val);
            else update(2*idx+1,m+1,r,pos,val);
            tree[idx]=min(tree[2*idx],tree[2*idx+1]);
        }
    }
    void upd(int pos,int val){update(1,0,n,pos,val);}
    int query(int idx,int l,int r,int ql,int qr)
    {
        if(ql>qr) return _n+1;
        if(l==ql&&r==qr) return tree[idx];
        int m=(l+r)/2;
        return min(query(2*idx,l,m,ql,min(qr,m)),query(2*idx+1,m+1,r,max(ql,m+1),qr));
    }
    int qry(int ql,int qr){return query(1,0,n,ql,qr);}
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,lim;
    cin >> n >> lim;
    vector<int> card(n+1,0);
    vector<array<int,2>> one(n+1,{0,0});
    vector<array<int,2>> two(n+1,{0,0});
    vector<array<int,4>> h={{0,0,0,0}};
    for(int i=1;i<=n;i++)
    {
        cin >> card[i];
        h.push_back({card[i],i,0,0});
        for(int j=0;j<2;j++)
        {
            cin >> one[i][j];
            h.push_back({one[i][j],i,j,1});
        }
        for(int j=0;j<2;j++)
        {
            cin >> two[i][j];
            h.push_back({two[i][j],i,j,2});
        }
    }
    sort(h.begin(),h.end());
    int hidx=0;
    for(int i=0;i<=5*n;i++)
    {
        if(i>0&&h[i][0]!=h[i-1][0]) hidx++;
        if(h[i][3]==0) card[h[i][1]]=hidx;
        else if(h[i][3]==1) one[h[i][1]][h[i][2]]=hidx;
        else two[h[i][1]][h[i][2]]=hidx;
    }
    auto gen=[&](vector<int> &x,vector<array<int,2>> &v)
    {
        ST l(hidx,n);
        ST r(hidx,n);
        for(int i=n;i>=0;i--)
        {
            auto [a,b]=v[i];
            l.upd(a,i);
            r.upd(b,i);
            x[i]=min(l.qry(card[i]+1,hidx),r.qry(0,card[i]-1))-1;
        }
    };
    vector<int> x(n+1,0);
    vector<int> y(n+1,0);
    gen(x,one);
    gen(y,two);
    map<array<int,2>,array<int,3>> opt[n+1];
    if(x[0]>=0&&y[0]>=0) opt[0][{x[0],y[0]}]={0,0,0};
    for(int i=1;i<=n;i++)
    {
        auto ok=[&](int a,int b)->bool{return (a>=i&&b>=i);};
        array<int,5> mxone={-1,-1,-1,-1,-1};
        array<int,5> mxtwo={-1,-1,-1,-1,-1};
        auto add=[&](array<int,5> a)
        {
            if(a[0]>mxone[0]||(a[0]==mxone[0]&&a[1]>mxone[1])) mxone=a;
            if(a[1]>mxtwo[1]||(a[1]==mxtwo[1]&&a[0]>mxtwo[0])) mxtwo=a;
        };
        for(auto &obj:opt[i-1])
        {
            auto [a,b]=obj.first;
            if(ok(a,y[i])) add({a,y[i],a,b,1});
            if(ok(x[i],b)) add({x[i],b,a,b,0});
        }
        if(mxone[0]!=-1) opt[i][{mxone[0],mxone[1]}]={mxone[2],mxone[3],mxone[4]};
        if(mxtwo[0]!=-1) opt[i][{mxtwo[0],mxtwo[1]}]={mxtwo[2],mxtwo[3],mxtwo[4]};
    }
    if(!opt[n].empty())
    {
        auto now=(*opt[n].begin()).first;
        vector<int> res(n+1,0);
        for(int i=n;i>=0;i--)
        {
            res[i]=opt[i][now][2];
            array<int,2> nxt={opt[i][now][0],opt[i][now][1]};
            now=nxt;
        }
        cout << "Yes\n";
        for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    }
    else cout << "No\n";
    return 0;
}