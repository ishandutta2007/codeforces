#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
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
char s[1005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,f=0;
        cin>>n;
        scanf("%s",s+1);
        for(int i=0;i<26;i++){
            int fl=0;
            for(int j=1;j<=n;j++) if(s[j]=='a'+i) fl=1;
            if(!fl){
                f=1;
                printf("%c\n",'a'+i);
                break;
            }
        }
        if(f) continue;
        for(int i=0;i<26&&!f;i++)
            for(int j=0;j<26&&!f;j++){
                int fl=0;
                for(int k=1;k<n;k++) if(s[k]=='a'+i&&s[k+1]=='a'+j) fl=1;
                if(!fl){
                    f=1;
                    printf("%c%c\n",'a'+i,'a'+j);
                    break;
                }
            }
        if(f) continue;
        for(int i=0;i<26&&!f;i++)
            for(int j=0;j<26&&!f;j++)
                for(int k=0;k<26&&!f;k++){
                    int fl=0;
                    for(int l=1;l<n-1;l++) if(s[l]=='a'+i&&s[l+1]=='a'+j&&s[l+2]=='a'+k) fl=1;
                    if(!fl){
                        f=1;
                        printf("%c%c%c\n",'a'+i,'a'+j,'a'+k);
                        break;
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