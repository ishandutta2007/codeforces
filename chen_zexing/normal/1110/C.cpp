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
        int n;
        cin>>n;
        int now=1;
        while(now*2-1<n) now*=2;
        if(now*2-1==n){
            int mx=0;
            for(int i=1;i*i<=n;i++) {
                if (n % i == 0) {
                    mx = max(mx, i);
                    if(i!=1) mx=max(mx,n/i);
                }
            }
            printf("%d\n",mx);
        }
        else printf("%d\n",now*2-1);
    }
    return 0;
}