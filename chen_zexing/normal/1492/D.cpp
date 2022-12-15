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
int ans1[200005],ans2[200005],ansk[200005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int a,b,k;
        cin>>a>>b>>k;
        if(a==0){
            if(k){
                puts("No");
            }
            else{
                puts("Yes");
                for(int i=1;i<=a+b;i++) printf("1");
                puts("");
                for(int i=1;i<=a+b;i++) printf("1");
                puts("");
            }
            continue;
        }
        if(b==1){
            if(k) puts("No");
            else{
                puts("Yes");
                printf("1");
                for(int i=1;i<a+b;i++) printf("0");
                puts("");
                printf("1");
                for(int i=1;i<a+b;i++) printf("0");
                puts("");
            }
            continue;
        }
        b--;
        if(k>=a+b){
            puts("No");
            continue;
        }
        puts("Yes");
        ans1[1]=ans2[1]=1;
        ansk[1]=0;
        for(int i=2;i<=a+1;i++) ans2[i]=0;
        for(int i=a+2;i<=a+b+1;i++) ans2[i]=1;
        if(k<=b){
            for(int i=2;i<=a+1;i++) ansk[i]=0;
            for(int i=a+2;i<=a+k+1;i++) ansk[i]=1;
        }
        else{
            for(int i=a+2;i<=a+b+1;i++) ansk[i]=1;
            for(int i=a+1;i>a+1-(k-b);i--) ansk[i]=1;
        }
        for(int i=a+b+1;i>1;i--){
            ans1[i]+=ans2[i]+ansk[i];
            if(ans1[i]>=2) ans1[i-1]+=ans1[i]/2,ans1[i]%=2;
        }
        for(int i=1;i<=a+b+1;i++) printf("%d",ans1[i]);
        puts("");
        for(int i=1;i<=a+b+1;i++) printf("%d",ans2[i]);
        puts("");
        //for(int i=1;i<=a+b+1;i++) printf("%d",ansk[i]);
    }
    return 0;
}