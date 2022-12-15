#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[305];
int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n/2;i++) printf("%d %d ",a[i],a[n-i+1]);
        if(n%2) printf("%d",a[n/2+1]);
        puts("");
    }
    return 0;
}