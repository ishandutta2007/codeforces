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
    int T=1;
    //cin>>T;
    while(T--){
        int b,k;
        cin>>b>>k;
        for(int i=1;i<=k;i++) scanf("%d",&a[i]);
        if(b%2==0){
            if(a[k]%2) puts("odd");
            else puts("even");
        }
        else{
            int cnt=0;
            for(int i=1;i<=k;i++) if(a[i]%2) cnt++;
            if(cnt%2) puts("odd");
            else puts("even");
        }
    }
    return 0;
}