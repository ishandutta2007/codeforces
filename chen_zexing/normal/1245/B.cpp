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
#define hash hassh
using namespace std;
char s[105],ans[105];
int f[105];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,a,b,c;
        cin>>n>>a>>b>>c;
        scanf("%s",s+1);
        int cnt1=0,cnt2=0,cnt3=0;
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='R') cnt1++;
            if(s[i]=='P') cnt2++;
            if(s[i]=='S') cnt3++;
        }
        int cnt=min(b,cnt1)+min(c,cnt2)+min(a,cnt3);
        memset(f,0,sizeof(f));
        if(cnt>=(n+1)/2){
            puts("YES");
            for(int i=1;i<=n;i++){
                if(s[i]=='R'&&b){
                    ans[i]='P';
                    b--;
                    f[i]=1;
                }
                if(s[i]=='P'&&c){
                    ans[i]='S';
                    c--;
                    f[i]=1;
                }
                if(s[i]=='S'&&a){
                    ans[i]='R';
                    a--;
                    f[i]=1;
                }
            }
            for(int i=1;i<=n;i++){
                if(f[i]==0){
                    if(a){
                        ans[i]='R';
                        a--;
                    }
                    else if(b){
                        ans[i]='P';
                        b--;
                    }
                    else if(c){
                        ans[i]='S';
                        c--;
                    }
                }
            }
            for(int i=1;i<=n;i++) printf("%c",ans[i]);
            puts("");
        }
        else puts("NO");
    }
    return 0;
}