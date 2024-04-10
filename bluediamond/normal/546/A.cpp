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
    ll k,n,w,s;
    cin>>k>>n>>w;
    s=w*(w+1)/2*k;
    if(n>=s)
        cout<<0;
    else
        cout<<s-n;
    return 0;
}
/**
**/