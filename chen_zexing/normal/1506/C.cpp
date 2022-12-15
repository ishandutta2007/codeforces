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
char a[25],b[25];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        cin>>a;
        cin>>b;
        int l1=strlen(a),l2=strlen(b),ans=0;
        for(int i=0;i<l1;i++)
            for(int j=i;j<l1;j++)
                for(int k=0;k<l2;k++)
                    for(int l=k;l<l2;l++){
                        if(j-i!=l-k) continue;
                        int f=1;
                        for(int t=i;t<=j;t++) if(a[t]!=b[t-i+k]) f=0;
                        if(f) ans=max(ans,j-i+1);
                    }
        printf("%d\n",l1+l2-ans*2);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp