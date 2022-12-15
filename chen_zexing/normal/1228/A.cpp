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
#define hash hassh
using namespace std;
int check(int x){
    int cnt[10]={};
    while(x){
        cnt[x%10]++;
        x/=10;
    }
    for(int i=0;i<=9;i++) if(cnt[i]>1) return 0;
    return 1;
}
int main() {
    int T=1;
    //cin >> T;
    while (T--) {
        int l,r;
        cin>>l>>r;
        int f=0;
        for(int i=l;i<=r;i++){
            if(check(i)){
                f=1;
                printf("%d\n",i);
                break;
            }
        }
        if(!f) puts("-1");
    }
    return 0;
}