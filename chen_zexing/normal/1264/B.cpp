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
int a,b,c,d;
int ans[100005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        cin>>a>>b>>c>>d;
        if((a>b&&(c||d))||b>a+c+1||c>b+d+1||(d>c&&(a||b))||a>b+1||d>c+1||abs(a+c-b-d)>1){
            puts("NO");
            continue;
        }
        puts("YES");
        if(a+c>b+d||a+c==b+d&&a>=b){
            for(int i=1;i<=(a+c)*2-1;i+=2){
                if(i<=a*2-1) ans[i]=1;
                else ans[i]=3;
            }
            for(int i=2;i<=(b+d)*2;i+=2){
                if(i<=b*2) ans[i]=2;
                else ans[i]=4;
            }
        }
        else{
            for(int i=1;i<=(b+d)*2-1;i+=2){
                if(i<=b*2-1) ans[i]=2;
                else ans[i]=4;
            }
            for(int i=2;i<=(a+c)*2;i+=2){
                if(i<=a*2) ans[i]=1;
                else ans[i]=3;
            }
        }
        for(int i=1;i<=a+b+c+d;i++) printf("%d ",ans[i]-1);
    }
    return 0;
}