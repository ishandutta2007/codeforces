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
    int n,s=0,a,b;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        if(b-a>=2)
            s++;
    }
    cout<<s;
    return 0;
}
/**
**/