#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        x=(1ll*x*x)%mod;
        y>>=1;
    }
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0, q=0, f=1;
    cin>>n;
    map <int, int> ma;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        ma[x]++;
        f=(1ll*f*(a+1))%mod;
    }
    map <int, int>::iterator it=ma.begin();
    for(int a=0; a<ma.size()-1; a++)
    {
        int va=(*it).first, q2=(*it).second;
        an=(an+1ll*((1ll*f*va)%mod)*((1ll*q2*po(n-q, mod-2))%mod))%mod;
        q+=q2, it++;
    }
    cout<<an;
}