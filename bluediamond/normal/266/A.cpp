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
    char s[55];
    int n,sl=0;
    cin>>n;
    cin.get();
    cin.getline(s,55);
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
            sl++;
    }
    cout<<sl;
    return 0;
}
/**
1:2
2:2
**/