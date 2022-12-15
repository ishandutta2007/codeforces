#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
using namespace std;
char s[200005];
int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n;
        scanf("%s",s+1);
        n=strlen(s+1);
        int f=0;
        for(int i=1;i<n;i++) if(s[i]+s[i+1]-'0'-'0'>=10) f=i;
        if(!f){
            for(int i=2;i<=n;i++){
                if(i==2) printf("%d",s[1]-'0'+s[2]-'0');
                else printf("%d",s[i]-'0');
            }
        }
        else{
            for(int i=1;i<=n;i++){
                if(i==f) printf("%d",s[i]-'0'+s[i+1]-'0');
                else if(i==f+1) continue;
                else printf("%d",s[i]-'0');
            }
        }
        puts("");
    }
    return 0;
}