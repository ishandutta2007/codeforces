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
int a[105],sum;
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        sum=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
        if(sum==m) puts("YES");
        else puts("NO");
    }
    return 0;
}