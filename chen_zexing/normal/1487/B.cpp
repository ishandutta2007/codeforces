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
int a[105];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n,k;
        scanf("%d%d",&n,&k);
        if(n%2==0){
            printf("%d\n",(k-1)%n+1);
            continue;
        }
        int t=(k-1)/(n/2);
        int nd=k+t;
        //if((nd-1)%n+1>=pos) nd++;
        printf("%d\n",(nd-1)%n+1);
    }
    return 0;
}