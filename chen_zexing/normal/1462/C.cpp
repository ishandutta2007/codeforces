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
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        if(n>45){
            puts("-1");
            continue;
        }
        int t=9,now=0,cnt=0;
        while(now<n){
            now+=t;
            t--;
            cnt++;
        }
        now-=(t+1);
        printf("%d",n-now);
        for(int i=t+2;i<=9;i++) printf("%d",i);
        puts("");
    }
    return 0;
}