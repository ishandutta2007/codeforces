#include <bits/stdc++.h>

using namespace std;

const int N=200005;
long long tree[4*N];

void update(int idx,int l,int r,int pos,long long add)
{
    if(l==r) tree[idx]+=add;
    else
    {
        int m=(l+r)/2;
        if(pos<=m) update(2*idx,l,m,pos,add);
        else update(2*idx+1,m+1,r,pos,add);
        tree[idx]=max(tree[2*idx],tree[2*idx+1]);
    }
}

int solve(int idx,int l,int r,long long val)
{
    if(tree[idx]<val) return 0;
    if(l==r) return l;
    int m=(l+r)/2;
    if(tree[2*idx]>=val) return solve(2*idx,l,m,val);
    else return solve(2*idx+1,m+1,r,val);
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<array<int,3>> v(n);
    vector<long long> tongue(n+1,0);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&v[i][0],&v[i][1]);
        v[i][2]=i+1;
        tongue[i+1]=v[i][1];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) update(1,1,n,i+1,v[i][0]+v[i][1]);
    vector<int> cnt(n+1,0);
    multiset<pair<int,int>> s;
    for(int i=0;i<m;i++)
    {
        int pos,sz;
        scanf("%d%d",&pos,&sz);
        int id=solve(1,1,n,pos);
        if(id==0||v[id-1][0]>pos)
        {
            s.insert({pos,sz});
            continue;
        }
        int frog=v[id-1][2];
        cnt[frog]++;
        tongue[frog]+=sz;
        update(1,1,n,id,sz);
        while(1)
        {
            auto it=s.lower_bound({v[id-1][0],0});
            if(it==s.end()) break;
            int p,b;
            tie(p,b)=*it;
            if(v[id-1][0]+tongue[frog]>=p)
            {
                cnt[frog]++;
                tongue[frog]+=b;
                update(1,1,n,id,b);
                s.erase(it);
            }
            else break;
        }
    }
    for(int i=1;i<=n;i++) printf("%d %I64d\n",cnt[i],tongue[i]);
    return 0;
}