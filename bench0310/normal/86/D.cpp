#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    vector<long long> a(n);
    for(int i=0;i<n;i++) scanf("%I64d",&a[i]);
    long long now=0;
    vector<int> v(1000001,0);
    int l=0,r=-1;
    auto add=[&](int idx,int d)
    {
        now+=(a[idx]*v[a[idx]]*v[a[idx]]*d);
    };
    auto update=[&](int ll,int rr)
    {
        while(l>ll)
        {
            add(--l,-1);
            v[a[l]]++;
            add(l,1);
        }
        while(r<rr)
        {
            add(++r,-1);
            v[a[r]]++;
            add(r,1);
        }
        while(l<ll)
        {
            add(l,-1);
            v[a[l]]--;
            add(l++,1);
        }
        while(r>rr)
        {
            add(r,-1);
            v[a[r]]--;
            add(r--,1);
        }
    };
    vector<tuple<int,int,int>> t(q);
    for(int i=0;i<q;i++)
    {
        int c,d;
        scanf("%d%d",&c,&d);
        t[i]=make_tuple(c-1,d-1,i);
    }
    sort(t.begin(),t.end(),[](tuple<int,int,int> a,tuple<int,int,int> b){return (make_pair(get<0>(a)/447,get<1>(a))<make_pair(get<0>(b)/447,get<1>(b)));});
    vector<long long> res(q);
    for(int i=0;i<q;i++)
    {
        update(get<0>(t[i]),get<1>(t[i]));
        res[get<2>(t[i])]=now;
    }
    for(int i=0;i<q;i++) printf("%I64d\n",res[i]);
    return 0;
}