#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
long long a[505];
int main() {
    int n;
    long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    if(n==1) cout<<a[1]<<endl;
    else if(n==2) cout<<(a[1]|a[2])<<endl;
    else {
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                for (int k = j + 1; k <= n; k++)
                    ans = max(ans, a[i] | a[j] | a[k]);
        cout << ans << endl;
    }
    return 0;
}