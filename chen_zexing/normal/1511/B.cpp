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
int check(int x){
    int ans=0;
    while(x) x/=10,ans++;
    return ans;
}
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int a,b,c,f=0;
        cin>>a>>b>>c;
        int t1;
        if(c>1) t1=pow(10,c-1)+1;
        else t1=1;
        int t2=t1;
        while(check(t2)!=b) t2*=2;
        while(check(t1)!=a) t1*=3;
        printf("%d %d\n",t1,t2);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp