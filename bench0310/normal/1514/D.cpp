#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int sz=550;
    int n,q;
    cin >> n >> q;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<array<int,3>> queries(q);
    for(int i=0;i<q;i++)
    {
        cin >> queries[i][0] >> queries[i][1];
        queries[i][2]=i+1;
    }
    auto cmp=[&](const array<int,3> &one,const array<int,3> &two)->bool
    {
        if(one[0]/sz!=two[0]/sz) return (one[0]/sz<two[0]/sz);
        else if(((one[0]/sz)%2)==0) return (one[1]<two[1]);
        else return (one[1]>two[1]);
    };
    sort(queries.begin(),queries.end(),cmp);
    vector<int> occ(n+1,0);
    int l=1,r=0;
    vector<int> e(n+1,0);
    vector<int> sum((n/sz)+1,0); //number of occurrences in a bucket of e
    e[0]=n;
    sum[0]=n;
    auto ch=[&](int i,int d)
    {
        e[occ[a[i]]]--;
        sum[occ[a[i]]/sz]--;
        occ[a[i]]+=d;
        e[occ[a[i]]]++;
        sum[occ[a[i]]/sz]++;        
    };
    vector<int> res(q+1,0);
    for(auto [nl,nr,id]:queries)
    {
        while(nl<l) ch(--l,1);
        while(r<nr) ch(++r,1);
        while(l<nl) ch(l++,-1);
        while(nr<r) ch(r--,-1);
        int m=0;
        for(int i=n/sz;i>=0;i--)
        {
            if(sum[i]>0)
            {
                for(int j=min(n,(i+1)*sz-1);;j--)
                {
                    if(e[j])
                    {
                        m=j;
                        break;
                    }
                }
                break;
            }
        }
        int o=(nr-nl+1-m);
        res[id]=max(1,m-o);
    }
    for(int i=1;i<=q;i++) cout << res[i] << "\n";
    return 0;
}