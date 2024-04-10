#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define ll long long
const int nm=1000005;
ll v[nm],n,al[nm];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
    {
        int pas=1<<int(log2(i)),r=0;
        while(pas)
        {
            if(r+pas<i-v[i])///prost .... bun
                r+=pas;
            pas/=2;
        }
        al[r+1]--;
        al[i]++;
    }
    int s=0,sl=0;
    for(int i=1;i<=n;i++)
    {
        s+=al[i];
        if(s>=0)
            sl++;
    }
    cout<<sl;
    return 0;
}