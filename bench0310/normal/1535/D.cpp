#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=(1<<18)+5;
string s;
vector<int> tree(4*N,0);

void tmerge(int idx,int l,int r)
{
    if(l<r)
    {
        if(s[idx]=='0') tree[idx]=tree[2*idx+1];
        else if(s[idx]=='1') tree[idx]=tree[2*idx];
        else tree[idx]=tree[2*idx]+tree[2*idx+1];
    }
    else tree[idx]=1;
}

void build(int idx,int l,int r)
{
    if(l==r) tmerge(idx,l,r);
    else
    {
        int m=(l+r)/2;
        build(2*idx,l,m);
        build(2*idx+1,m+1,r);
        tmerge(idx,l,r);
    }
}

void update(int idx,int l,int r,int uidx,int lvl)
{
    if(uidx==idx) tmerge(idx,l,r);
    else
    {
        int m=(l+r)/2;
        if(((uidx>>lvl)&1)==0) update(2*idx,l,m,uidx,lvl-1);
        else update(2*idx+1,m+1,r,uidx,lvl-1);
        tmerge(idx,l,r);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k;
    cin >> k;
    cin >> s;
    reverse(s.begin(),s.end());
    s="$"+s;
    int n=(1<<k);
    build(1,1,n);
    int q;
    cin >> q;
    while(q--)
    {
        int idx;
        char c;
        cin >> idx >> c;
        idx=(n-idx);
        s[idx]=c;
        int lvl=0;
        for(int i=0;i<=k;i++) if(idx&(1<<i)) lvl=i;
        update(1,1,n,idx,lvl-1);
        cout << tree[1] << "\n";
    }
    return 0;
}