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
    while(T--){
        int n;
        cin>>n;
        int sum=0,f=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]),sum+=a[i];
            if(a[i]%2) f=1;
        }
        if(sum%2){
            puts("NO");
        }
        else if(sum/2%2&&!f) puts("NO");
        else{
            puts("YES");
        }
    }
    return 0;
}