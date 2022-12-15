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
char l[1000005],r[1000005];
int check(int n){
    int f=1;
    for(int i=1;i<=n;i++) if(l[i]!=r[i]) f=0;
    if(f) return 1;
    l[n]++;
    for(int i=n;i>=1;i--){
        l[i-1]+=(l[i]-'0')/2;
        if(l[i]>='2') l[i]-=2;
    }
    for(int i=1;i<=n;i++) if(l[i]!=r[i]){
            //cout<<i<<" "<<l[i]<<" "<<r[i]<<endl;
            return 0;
        }
    return 1;
}
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        scanf("%s",l+1);
        scanf("%s",r+1);
        if(l[1]=='0'&&r[1]=='0'){
            puts("0");
            continue;
        }
        if(l[1]=='0'){
            for(int i=1;i<=n;i++) printf("1");
            puts("");
            continue;
        }
        if(r[n]=='1'){
            for(int i=1;i<=n;i++) printf("%c",r[i]);
        }
        else{
            if(check(n)){
                for(int i=1;i<=n;i++) printf("%c",r[i]);
            }
            else{
                for(int i=1;i<n;i++) printf("%c",r[i]);
                printf("1");
            }
        }
    }
    return 0;
}
//
/// 