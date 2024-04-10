//This Code was made by Chinese_zjc_.
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<time.h>
// #include<windows.h>
#define int long long
#define PI 3.14159265358979323
#define INF 0x3fffffffffffffff
using namespace std;
int n;
bool is(int x)
{
    for(int i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    if(is(n))
    {
        cout<<1<<endl;
        return 0;
    }
    if(n&1)
    {
        if(is(n-2))
        {
            cout<<2<<endl;
            return 0;
        }
        else
        {
            cout<<3<<endl;
            return 0;
        }
    }
    cout<<2<<endl;
    return 0;
}