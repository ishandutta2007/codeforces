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
int a[100005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,x=0;
        long long sum=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i],x^=a[i];
        printf("2\n%d %lld\n",x,sum+x);
    }
    return 0;
}