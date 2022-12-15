#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
using namespace std;
int cnt[26];
char s[200005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        scanf("%s",s+1);
        int len=strlen(s+1);
        for(int i=0;i<26;i++) cnt[i]=0;
        for(int i=1;i<=len;i++) cnt[s[i]-'a']++;
        int c=0,f=0;
        for(int i=0;i<26;i++){
            if(cnt[i]) c++;
            if(cnt[i]==1) f=1;
        }
        if(f){
            for(int i=0;i<26;i++) if(cnt[i]==1){
                    printf("%c",'a'+i);
                    cnt[i]--;
                    break;
                }
            for(int i=0;i<26;i++)
                for(int j=1;j<=cnt[i];j++)
                    printf("%c",'a'+i);
            puts("");
            continue;
        }
        if(c==1){
            for(int i=0;i<26;i++)
                for(int j=1;j<=cnt[i];j++)
                    printf("%c",'a'+i);
            puts("");
            continue;
        }
        else if(c==2){
            int x=-1,y=-1;
            for(int i=0;i<26;i++) if(cnt[i]){
                    if(x==-1) x=i;
                    else y=i;
                }
            if(cnt[x]-cnt[y]>2){
                printf("%c",'a'+x);
                for(int i=1;i<=cnt[y];i++) printf("%c",'a'+y);
                for(int i=1;i<cnt[x];i++) printf("%c",'a'+x);
                puts("");
            }
            else{
                if(cnt[x]) printf("%c",'a'+x),cnt[x]--;
                if(cnt[x]) printf("%c",'a'+x),cnt[x]--;
                while(cnt[y]){
                    printf("%c",'a'+y),cnt[y]--;
                    if(cnt[x]) printf("%c",'a'+x),cnt[x]--;
                }
                puts("");
            }
        }
        else{
            int x=-1,y=-1,z=-1;
            for(int i=0;i<26;i++) if(cnt[i]){
                    if(x==-1) x=i;
                    else if(y==-1) y=i;
                    else{
                        z=i;
                        break;
                    }
                }
            if(cnt[x]-(len-cnt[x])>2){
                printf("%c",'a'+x),cnt[x]--;
                printf("%c",'a'+y),cnt[y]--;
                for(int i=1;i<=cnt[x];i++) printf("%c",'a'+x);
                printf("%c",'a'+z),cnt[z]--;
                for(int i=0;i<26;i++)
                    if(i!=x)
                        for(int j=1;j<=cnt[i];j++)
                            printf("%c",'a'+i);
                puts("");
            }
            else{
                if(cnt[x]) printf("%c",'a'+x),cnt[x]--;
                if(cnt[x]) printf("%c",'a'+x),cnt[x]--;
                int now=y;
                while(cnt[now]==0&&now<25) now++;
                while(cnt[now]){
                    printf("%c",'a'+now),cnt[now]--;
                    if(cnt[x]) printf("%c",'a'+x),cnt[x]--;
                    while(cnt[now]==0&&now<25) now++;
                }
                puts("");
            }
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//