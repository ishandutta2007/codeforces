#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;
long long multi[25];
int main() {
    int n;
    cin>>n;
    multi[0]=1;
    for(int i=1;i<=n;i++) multi[i]=multi[i-1]*i;
    long long ans=1;
    ans=1LL*multi[n]/multi[n/2]/(n/2)*multi[n/2]/(n/2)/2;
    cout<<ans<<endl;
    return 0;
}