#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <iomanip>
#include <math.h>
#include <algorithm>
using namespace std;
const int nm=100005;
long long v[nm],s,n,x;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i];
        s+=v[i];
    }
    if(s+n-1==x)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}