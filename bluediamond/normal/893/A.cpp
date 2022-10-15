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
    int p1=1,p2=2,n,a;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a!=p1 and a!=p2)
        {
            cout<<"NO";
            return 0;
        }
        int a1=a,a2=6-p1-p2;
        p1=a1;
        p2=a2;
    }
    cout<<"YES";
    return 0;
}
/**
**/