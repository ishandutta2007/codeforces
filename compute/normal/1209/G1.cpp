#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
struct Seg{
    int l,r,cnt;
    bool operator<(const Seg& a)const{
        if(l==a.l) return r<a.r;
        return l<a.l;
    }
};
int a[maxn];
int fi[maxn],la[maxn],c[maxn];
int main()
{
    vector<Seg> all;
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        if(!fi[a[i]]) fi[a[i]]=i;
        la[a[i]]=i;
        c[a[i]]++;
    }
    for(int i=1;i<=200000;i++)
    {
        if(fi[i])
            all.push_back({fi[i],la[i],c[i]});
    }
    sort(all.begin(),all.end());
    int L=all[0].l,R=all[0].r,cc=all[0].cnt;
    vector<Seg> ans;
    int op=0;
    for(int i=0;i<all.size();i++)
    {
        if(all[i].l<=R)
        {
            R=max(R,all[i].r);
            cc=max(cc,all[i].cnt);
        }
        else{
            ans.push_back({L,R,cc});
            L=all[i].l,R=all[i].r;
            cc=all[i].cnt;
        }
    }
    ans.push_back({L,R,cc});
    for(auto u:ans) 
    {
        op+=(u.r-u.l+1-u.cnt);
        //cout<<u.l<<","<<u.r<<":"<<u.cnt<<endl;
    }
    printf("%d\n",op);
}