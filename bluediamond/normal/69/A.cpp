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
    int n,s1=0,s2=0,s3=0,a,b,c;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b>>c;
        s1+=a;
        s2+=b;
        s3+=c;
    }
    if(s1==0 and s2==0 and s3==0)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
/**
**/