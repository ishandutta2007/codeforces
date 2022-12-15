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
    //cin>>T;
    while(T--){
        int n;
        int a[105];
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int sum=0,sum2=0,cnt=0;
        for(int i=1;i<=n;i++){
            sum+=a[i];
            if(i==1||a[i]<=a[1]/2) sum2+=a[i],cnt++;
        }
        if(sum2>sum-sum2){
            printf("%d\n",cnt);
            for(int i=1;i<=n;i++)
                if(i==1||a[i]<=a[1]/2)
                    printf("%d ",i);
        }
        else puts("0");
    }
    return 0;
}