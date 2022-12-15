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
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--){
        int t,ans=1;
        cin>>t;
        while((1<<(ans+1))-1<t) ans++;
        printf("%d\n",ans);
        t-=ans;
        t--;
        int now=1;
        for(int i=1;i<=ans;i++){
            int p=ans-i+1;
            int f=min(now,t/p);
            printf("%d ",f);
            now+=f;
            t-=p*f;
        }
        printf("\n");
    }
    return 0;
}