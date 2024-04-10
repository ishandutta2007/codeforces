#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N=100005;
vector<array<ll,5>> tree(4*N,{0,0,0,0,0});
vector<ll> val(N,0);
vector<int> cnt(4*N,0);

void update(int idx,int l,int r,int pos)
{
    if(l==r)
    {
        if(cnt[idx]==0)
        {
            tree[idx][0]=val[l];
            cnt[idx]=1;
        }
        else
        {
            tree[idx][0]=0;
            cnt[idx]=0;
        }
    }
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos);
        else update(2*idx+1,m+1,r,pos);
        for(int i=0;i<5;i++) tree[idx][i]=(tree[2*idx][i]+tree[2*idx+1][(i-(cnt[2*idx]%5)+5)%5]);
        cnt[idx]=cnt[2*idx]+cnt[2*idx+1];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> t(n);
    vector<int> x(n,0);
    vector<int> id(n,0);
    vector<array<int,2>> v;
    for(int i=0;i<n;i++)
    {
        cin >> t[i];
        if(t[i]=="add"||t[i]=="del")
        {
            cin >> x[i];
            v.push_back({x[i],i});
        }
    }
    sort(v.begin(),v.end());
    int idx=1;
    for(int i=0;i<(int)v.size();i++)
    {
        if(i>0&&v[i][0]!=v[i-1][0]) idx++;
        id[v[i][1]]=idx;
        val[idx]=v[i][0];
    }
    for(int i=0;i<n;i++)
    {
        if(t[i]=="add"||t[i]=="del") update(1,1,n,id[i]);
        else cout << tree[1][2] << "\n";
    }
    return 0;
}