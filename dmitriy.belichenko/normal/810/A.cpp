#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
int  m;
int sum = 0;
int g(int n);
int f(int n)
{
    if(n > 2)
        return  f(n - 1) + g(n - 1);
    else return n;
}
int g(int n)
{
    if(n > 1) return g(n - 1) + f(n);
    else return n;
}
// 79 137 238 2235
// 63 120 45

int main()
{
    
    int  n , k , cnt = 0;
    cin>> n>> k;
    double s=0;
    for (int i=0; i < n; i++)
    {
        int t;
        cin >> t;
        s += t;
    }
    
    while ( (double)(s / double(n+cnt)) + 0.5 < k)
    {
        s+=k;
        cnt = cnt + 1;
    }
    cout<<cnt;
}