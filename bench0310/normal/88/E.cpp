#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    auto sum=[](ll a)->ll{return (a*(a+1)/2);};
    auto gen=[&](int a,int len)->array<int,2>
    {
        int b=(2*a-len*len+len);
        int c=(2*len);
        if((b%c)!=0||(b/c)<=0) return {0,0};
        else return {b/c,b/c+len-1};
    };
    vector<int> g(n+1,0);
    vector<int> gx(n+1,0);
    auto grundy=[&](int l,int r)->int{return (gx[r]^gx[l-1]);};
    vector<bool> mex(n+1,0);
    for(int i=1;i<=n;i++)
    {
        vector<int> v;
        for(int len=2;sum(len)<=i;len++)
        {
            auto [l,r]=gen(i,len);
            if(l!=0) v.push_back(grundy(l,r));
        }
        for(int x:v) mex[x]=1;
        for(int j=0;j<=n;j++)
        {
            if(mex[j]==0)
            {
                g[i]=j;
                break;
            }
        }
        for(int x:v) mex[x]=0;
        gx[i]=(gx[i-1]^g[i]);
    }
    if(g[n]>0)
    {
        for(int len=2;sum(len)<=n;len++)
        {
            auto [l,r]=gen(n,len);
            if(l!=0&&grundy(l,r)==0)
            {
                cout << len << "\n";
                break;
            }
        }
    }
    else cout << "-1\n";
    return 0;
}