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
char s[1000005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        scanf("%s",s+1);
        int ans=0,now=0,st=-1;
        for(int i=1;i<=n;i++){
            if(s[i]==')') now--;
            else now++;
            if(now<0&&st==-1) st=i;
            if(now==0&&st!=-1){
                ans+=i-st+1;
                st=-1;
            }
        }
        if(now!=0) puts("-1");
        else cout<<ans<<endl;
    }
    return 0;
}