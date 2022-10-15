#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000+5;

int n,v[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a=0,b=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    int st=1;
    int dr=n;
    for(int i=1;i<=n;i++)
    {
        int x=0;
        if(v[st]>v[dr])
        {
            x=v[st++];
        }
        else
        {
            x=v[dr--];
        }
        if(i%2==1)
        {
            a+=x;
        }
        else
        {
            b+=x;
        }
    }
    cout<<a<<" "<<b<<"\n";
    return 0;
}