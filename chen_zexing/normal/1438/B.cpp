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
int b[1005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int f=1;
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
            for(int j=1;j<i;j++)
                if(b[i]==b[j])
                    f=0;
        }
        if(f) puts("NO");
        else puts("YES");
    }
    return 0;
}