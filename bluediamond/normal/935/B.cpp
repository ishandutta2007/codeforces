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
bool f(int x,int y)
{
    return x<y;
}
const int nmax=1e5;
char s[nmax+5];
int x[nmax+5],y[nmax+5]; int n;
int main()
{
    cin>>n;
    cin.get();
    cin.getline(s,nmax+5);
    x[0]=y[0]=0;
    for(int i=0;i<n;i++)
    {
        x[i+1]=x[i];
        y[i+1]=y[i];
        if(s[i]=='U')
            y[i+1]++;
        else
            x[i+1]++;
    }
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(x[i]==y[i] and f(x[i-1],y[i-1])+f(x[i+1],y[i+1])==1)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
/**

**/