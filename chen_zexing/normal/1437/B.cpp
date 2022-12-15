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
char s[100005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        int cnt1=0,cnt2=0,ans1=0,ans2=0;
        for(int i=1;i<=n;i++){
            if(s[i]=='0'){
                if(cnt2) ans2+=cnt2-1;
                cnt1++;
                cnt2=0;
            }
            else{
                if(cnt1) ans1+=cnt1-1;
                cnt2++;
                cnt1=0;
            }
        }
        printf("%d\n",max(ans1,ans2));
    }
    return 0;
}