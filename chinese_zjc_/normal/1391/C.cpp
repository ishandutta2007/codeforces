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
#define MOD 1000000007
using namespace std;
int n,a[5000000];
int power(int A,int B)
{
    int tmp=1;
    while(B)
    {
        if(B&1)
        {
            tmp=tmp*A%MOD;
        }
        B>>=1;
        A=A*A%MOD;
    }
    return tmp;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    a[0]=1;
    for(int i=1;i<=n;++i)
    {
        a[i]=a[i-1]*i%MOD;
    }
    cout<<(a[n]-power(2,n-1)+MOD)%MOD<<endl;
    return 0;
}