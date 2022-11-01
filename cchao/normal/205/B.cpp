#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    long long n,ans = 0,tmp,max,prev,buf=0;
    cin >> n;
    cin >> max; n--;prev = max;
    while(n--)
    {
        cin >> tmp;
        if(tmp <= prev)
        {
            buf = max - tmp;
        }
        else
        {
            ans += buf;
            buf = 0;
            max = tmp;
        }
        prev = tmp;
    }
    ans += buf;
    cout << ans << endl;
    return 0;
}