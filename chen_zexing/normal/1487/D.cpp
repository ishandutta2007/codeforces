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
    while(T--) {
        int n;
        scanf("%d",&n);
        int l=0,r=100000;
        while(l<r){
            int mid=(l+r)>>1;
            mid++;
            long long t=1LL*(mid*2+1)*(mid*2+1);
            if((t+1)/2>n) r=mid-1;
            else l=mid;
        }
        printf("%d\n",l);
    }
    return 0;
}