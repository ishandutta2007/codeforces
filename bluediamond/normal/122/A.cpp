#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cctype>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int v[105],n=0,x;
    n++;v[n]=4;
    n++;v[n]=7;
    n++;v[n]=44;
    n++;v[n]=47;
    n++;v[n]=74;
    n++;v[n]=77;
    n++;v[n]=444;
    n++;v[n]=447;
    n++;v[n]=474;
    n++;v[n]=477;
    n++;v[n]=744;
    n++;v[n]=747;
    n++;v[n]=774;
    n++;v[n]=777;
    cin>>x;
    for(int i=1;i<=n;i++)
        if(x%v[i]==0)
        {
            cout<<"YES";
            return 0;
        }
    cout<<"NO";
    return 0;
}
/**
**/