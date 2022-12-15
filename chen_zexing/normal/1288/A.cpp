#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,d;
        cin>>n>>d;
        int ans=d,x=1;
        while(x<=2*sqrt(d))
        {
            if(ans>x+d/(x+1)+(d%(x+1)!=0)) {
                ans = x + d / (x + 1) + (d % (x + 1) != 0);
            }
            x++;
        }
        if(ans<=n) printf("YES\n");
        else printf("NO\n");
        //cout<<ans<<" "<<n<<" "<<x-1<<endl;
    }
    return 0;
}