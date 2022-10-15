#include <iostream>
#include <cstring>
#include <vector>
#include <set>
#include <iomanip>
#include <math.h>
#include <algorithm>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,t,a,s=0;
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        s+=86400-a;
        if(s>=t)
            {
                cout<<i;
                return 0;
            }
    }
    return 0;
}