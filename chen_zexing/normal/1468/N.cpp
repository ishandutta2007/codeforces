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
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int c[4],a[6];
        for(int i=1;i<=3;i++) scanf("%d",&c[i]);
        for(int i=1;i<=5;i++) scanf("%d",&a[i]);
        for(int i=1;i<=3;i++) c[i]-=a[i];
        if(c[1]<0||c[2]<0||c[3]<0){
            puts("NO");
            continue;
        }
        if(max(0,a[4]-c[1])+max(0,a[5]-c[2])<=c[3]) puts("YES");
        else puts("NO");
    }
    return 0;
}