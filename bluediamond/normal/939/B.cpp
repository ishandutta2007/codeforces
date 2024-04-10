///#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <set>
#include <vector>
#include <iomanip>
#include <bitset>
#include <queue>
using namespace std;
#define ll long long
const ll nmax=1e5;
ll val,n,v[nmax+5],best,ind;
int main()
{
    cin>>val>>n>>v[1];
    best=val-val%v[1];
    ind=1;
    for(int i=2;i<=n;i++)
    {
        cin>>v[i];
        if(val-val%v[i]>best)
        {
            best=val-val%v[i];
            ind=i;
        }
    }
    cout<<ind<<" "<<val/v[ind];
    return 0;
}
/**
**/