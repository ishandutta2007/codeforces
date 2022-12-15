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
int t[200005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m,a,b;
        cin>>n>>m>>a>>b;
        if(a>b) a=n+1-a,b=n+1-b;
        for(int i=1;i<=m;i++) scanf("%d",&t[i]);
        sort(t+1,t+m+1);
        int l=0,r=min(m,abs(a-b)-1);
        while(l<r){
            int mid=(l+r)>>1;
            mid++;
            int mx=0;
            for(int i=1;i<=mid;i++) mx=max(mx,t[i]+mid-i+1);
            if(b-1<mx) r=mid-1;
            else l=mid;
        }
        printf("%d\n",l);
    }
    return 0;
}