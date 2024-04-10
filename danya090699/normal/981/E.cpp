#include <bits/stdc++.h>
using namespace std;
const int sz=1e4+10;
vector <int> dot[sz*4];
bitset <sz> dp[sz], an;
int lg, rg, x, qq=1;
void ins(int nu, int l, int r)
{
    if(l>=lg and r<=rg) dot[nu].push_back(x);
    else if(!(l>rg or r<lg))
    {
        int mid=(l+r)>>1;
        ins(nu*2, l, mid);
        ins(nu*2+1, mid+1, r);
    }
}
void que(int nu, int l, int r)
{
    for(int a=0; a<dot[nu].size(); a++)
    {
        dp[qq]=(dp[qq-1]|(dp[qq-1]<<dot[nu][a])), qq++;
    }
    if(l==r)
    {
        //cout<<qq<<" ";
        an=an|dp[qq-1];
    }
    else
    {
        int mid=(l+r)>>1;
        que(nu*2, l, mid);
        que(nu*2+1, mid+1, r);
    }
    for(int a=0; a<dot[nu].size(); a++) qq--;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    for(int a=0; a<q; a++)
    {
        cin>>lg>>rg>>x;
        lg--, rg--;
        ins(1, 0, n-1);
    }
    dp[0][0]=1;
    que(1, 0, n-1);
    vector <int> ve;
    for(int a=1; a<=n; a++) if(an[a]) ve.push_back(a);
    cout<<ve.size()<<"\n";
    for(int a=0; a<ve.size(); a++) cout<<ve[a]<<" ";
}