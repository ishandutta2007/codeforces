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
        int n,cnt[4];
        scanf("%d",&n);
        for(int i=0;i<4;i++) scanf("%d",&cnt[i]);
        int fl=0;
        for(int i=0;i<16;i++){
            int t[4],f=1;
            for(int j=0;j<4;j++) t[j]=((1<<j)&i)>0;
            for(int j=0;j<4;j++){
                int c=t[j]+t[(j+1)%4];
                int r=cnt[j]-c;
                if(r<0) f=0;
                if(r>n-2) f=0;
            }
            if(f) fl=1;
        }
        if(fl) puts("YES");
        else puts("NO");
    }
    return 0;
}