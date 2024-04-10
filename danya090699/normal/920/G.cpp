#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
vector <int> de[sz];
int f(int nu, int va, int i, int q, bool ch)
{
    int re=q/va;
    if(ch) re=-re;
    for(int a=i; a<de[nu].size(); a++) re+=f(nu, va*de[nu][a], a+1, q, ch^1);
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    for(int a=2; a<sz; a++)
    {
        if(de[a].size()==0)
        {
            for(int b=a; b<sz; b+=a) de[b].push_back(a);
        }
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int x, p, k;
        cin>>x>>p>>k;
        int l=x, r=sz*10;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            int q=f(p, 1, 0, mid, 0)-f(p, 1, 0, x, 0);
            if(q<k) l=mid;
            else r=mid;
        }
        cout<<r<<"\n";
    }
}