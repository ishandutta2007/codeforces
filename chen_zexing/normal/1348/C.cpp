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
int cnt[200];
bool cmp(char a,char b){
    return a<b;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,k;
        scanf("%d%d",&n,&k);
        memset(cnt,0,sizeof(cnt));
        scanf("%s",s+1);
        sort(s+1,s+n+1,cmp);
        for(int i=1;i<=n;i++) cnt[s[i]]++;
        if(cnt[s[1]]<k){
            printf("%c\n",s[k]);
        }
        else if(cnt[s[1]]==n){
            int t=n/k+(n%k>0);
            for(int i=1;i<=t;i++) printf("%c",s[1]);
            printf("\n");
        }
        else if(cnt[s[1]]==k&&cnt[s[1]]!=n&&cnt[s[k+1]]==n-k){
            int t=n/k-1+(n%k>0);
            printf("%c",s[1]);
            for(int i=1;i<=t;i++) printf("%c",s[k+1]);
            printf("\n");
        }
        else{
            printf("%c",s[1]);
            for(int i=k+1;i<=n;i++) printf("%c",s[i]);
            printf("\n");
        }
        //for(int i=1;i<=n;i++) cout<<s[i];
        //cout<<endl;
    }
    return 0;
}