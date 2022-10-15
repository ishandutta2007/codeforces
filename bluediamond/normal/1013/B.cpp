#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000+5;
int n,x,v[N],v2[N];
int ap1[N];
int ap2[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        v2[i]=v[i]&x;
        ap1[v[i]]++;
        if(v[i]!=v2[i])
            ap2[v2[i]]++;
    }
    for(int i=0;i<N;i++)
        if(ap1[i]>=2)
        {
            cout<<"0\n";
            return 0;
        }
    for(int i=0;i<N;i++)
        if(ap1[i] && ap2[i])
        {
            cout<<"1\n";
            return 0;
        }
    for(int i=0;i<N;i++)
        if(ap2[i]>=2)
        {
            cout<<"2\n";
            return 0;
        }
    cout<<"-1\n";
    return 0;
}
/**

**/