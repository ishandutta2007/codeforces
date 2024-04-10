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
    int v[55],n,m,sol=1e6;
    cin>>n>>m;
    v[0]=0;
    for(int i=1;i<=m;i++)
        cin>>v[i];
    sort(v+1,v+m+1);
    for(int i=n;i<=m;i++)
        if(v[i]-v[i-n+1]<sol)
            sol=v[i]-v[i-n+1];
    cout<<sol;
    return 0;
}
/**
**/