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
int a,b,c,d,n,v[100005],s=0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>a>>b>>c>>d>>n;
    for(int i=a;i<=n;i+=a)v[i]=1;
    for(int i=b;i<=n;i+=b)v[i]=1;
    for(int i=c;i<=n;i+=c)v[i]=1;
    for(int i=d;i<=n;i+=d)v[i]=1;
    for(int i=1;i<=n;i++)
        if(v[i])
            s++;
    cout<<s;
    return 0;
}
/**
**/