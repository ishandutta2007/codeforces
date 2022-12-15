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
int a[200005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int f=0;
        for(int i=2;i<=n;i++){
            if(abs(a[i]-a[i-1])>1){
                puts("YES");
                printf("%d %d\n",i-1,i);
                f=1;
                break;
            }
        }
        if(!f) puts("NO");
    }
    return 0;
}