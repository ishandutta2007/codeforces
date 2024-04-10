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
char s[150005];
int ans[300005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        scanf("%s",s);
        int l=strlen(s),x=0;
        for(int i=2;i<l;i++){
            if(s[i]=='e'&&s[i-1]=='n'&&s[i-2]=='o'){
                if(i-3<0||s[i-3]!='o') ans[++x]=i-2;
                else ans[++x]=i-1;
            }
        }
        for(int i=0;i<l-2;i++)
            if(s[i]=='t'&&s[i+1]=='w'&&s[i+2]=='o'){
                if(i+3>=l||s[i+3]!='o') ans[++x]=i+2;
                else ans[++x]=i+1;
            }
        sort(ans+1,ans+x+1);
        x=unique(ans+1,ans+x+1)-ans-1;
        printf("%d\n",x);
        for(int i=1;i<=x;i++) printf("%d ",ans[i]+1);
        puts("");
    }
    return 0;
}