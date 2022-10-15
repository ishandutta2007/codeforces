#include <bits/stdc++.h>
using namespace std;
const int N=1000;
long long n,a,b;
long long v1[N+5];
long long v2[N+5];
long long dif(int poz)
{
    return abs(v1[poz]-v2[poz]);
}
int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++)
        cin>>v1[i];
    for(int i=1;i<=n;i++)
        cin>>v2[i];
    while(a--)
    {
        long long mare=dif(1);
        for(int i=2;i<=n;i++)
            mare=max(mare,dif(i));
        for(int i=1;i<=n;i++)
            if(dif(i)==mare)
            {
                long long x,y;
                x=v1[i]-1;
                y=v1[i]+1;
                if(abs(x-v2[i])<abs(y-v2[i]))
                    v1[i]--;
                else
                    v1[i]++;
                break;
            }
    }
    while(b--)
    {
        long long mare=dif(1);
        for(int i=2;i<=n;i++)
            mare=max(mare,dif(i));
        for(int i=1;i<=n;i++)
            if(dif(i)==mare)
            {
                long long x,y;
                x=v2[i]-1;
                y=v2[i]+1;
                if(abs(x-v1[i])<abs(y-v1[i]))
                    v2[i]--;
                else
                    v2[i]++;
                break;
            }
    }
    long long e=0;
    for(int i=1;i<=n;i++)
    {
        e+=(v1[i]-v2[i])*(v1[i]-v2[i]);
    }
    cout<<e;
    return 0;
}