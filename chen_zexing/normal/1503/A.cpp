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
char s[200005];
int a[200005],b[200005];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        int cnt=0;
        for(int i=1;i<=n;i++) if(s[i]=='0') cnt++;
        if(cnt%2){
            puts("NO");
            continue;
        }
        int now=0,t=0;
        for(int i=1;i<=n;i++) a[i]=0;
        for(int i=1;i<=n;i++) {
            if (s[i] == '1') {
                now++;
                if (now <= (n - cnt) / 2) a[i] = b[i]=1;
                else a[i] =b[i]= -1;
            }
            else{
                t++;
                if(t%2) a[i]=1,b[i]=-1;
                else a[i]=-1,b[i]=1;
            }
        }
        int f=1;
        int t1=0,t2=0;
        for(int i=1;i<=n;i++){
            t1+=a[i],t2+=b[i];
            if(t1<0||t2<0) f=0;
        }
        if(!f) puts("NO");
        else{
            puts("YES");
            for(int i=1;i<=n;i++) printf("%c",a[i]==1?'(':')');
            puts("");
            for(int i=1;i<=n;i++) printf("%c",b[i]==1?'(':')');
            puts("");
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