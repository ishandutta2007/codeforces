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
char s[10005],t[10005];
int cnt[26];
struct node{
    int t,pos;
};
struct answer{
    int x,y;
};
vector <node> v[26];
vector <answer> ans;
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n,f=1;
        cin>>n;
        scanf("%s",s+1);
        scanf("%s",t+1);
        ans.clear();
        for(int i=0;i<26;i++) cnt[i]=0;
        for(int i=1;i<=n;i++){
            cnt[s[i]-'a']++,cnt[t[i]-'a']++;
        }
        for(int i=0;i<26;i++) if(cnt[i]%2) f=0;
        if(!f){
            puts("No");
            continue;
        }
        for(int i=1;i<=n;i++){
            if(s[i]==t[i]) continue;
            int p=-1;
            for(int j=i+1;j<=n;j++) if(s[j]==s[i]){
                    p=j;
                    break;
                }
            if(p!=-1){
                ans.push_back(answer{p,i});
                swap(s[p],t[i]);
                continue;
            }
            for(int j=i+1;j<=n;j++)
                if(t[j]==s[i])
                {
                    p=j;
                    break;
                }
            ans.push_back(answer{p,p});
            swap(s[p],t[p]);
            ans.push_back(answer{p,i});
            swap(s[p],t[i]);
        }
        puts("Yes");
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].x,ans[i].y);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp