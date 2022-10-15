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
    ll n,s=0;
    cin>>n;
    while(n>0)
    {
        if(n%10==4 or n%10==7)
            s++;
        n/=10;
    }
    if(s==4 or s==7)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
/**
**/