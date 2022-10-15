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
int f(int n)
{
    int ap[15];
    for(int i=0;i<=9;i++)
        ap[i]=0;
    while(n>0)
    {
        ap[n%10]++;
        n/=10;
    }
    for(int i=0;i<=9;i++)
        if(ap[i]>=2)
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    n++;
    while(1)
    {
        if(f(n)==1)
        {
            cout<<n;
            return 0;
        }
        n++;
    }
    return 0;
}
/**
**/