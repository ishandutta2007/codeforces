#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int ask(int i)
{
    int res=0;
    while(i>1)
    {
        res++;
        i-=i&(-i);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>v(m);
    for(int i=0;i<m;i++)
    {
        cin>>v[i];
    }
    int x,res=0;
    cin>>x;
    for(int i=0;i<m;i++)
    {
        int val=(x^v[i]);
        int dif=ask(val);
        if(dif<=k)
        {
            res++;
        }
    }
    cout<<res<<"\n";
    return 0;
}