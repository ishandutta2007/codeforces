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
    int n,x=0;
    cin>>n;
    char c1,c2,c3;
    for(int i=1;i<=n;i++)
    {
        cin.get();
        c1=cin.get();
        c2=cin.get();
        c3=cin.get();
        if(c1=='+' or c2=='+' or c3=='+')
            x++;
        else
            x--;
    }
    cout<<x;
    return 0;
}
/**
**/