#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//d.
// 
int main()
{
    ll n,d,m,l;
    ll step;
    while(cin>>n>>d>>m>>l)
    {
        ll min,max;
        for(int i=0;i<n;i++)
        {
            min=i*m+l;//i
            max=(i+1)*m;//i+1
            step=(min+d)/d;
            if(step*d<max) break;
        }
        cout<<step*d<<endl;
    }
    return 0;
}