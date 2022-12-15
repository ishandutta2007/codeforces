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
int fst[26],lst[26],f[26];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        scanf("%s",s+1);
        int n=strlen(s+1),r=0;
        for(int i=0;i<26;i++) f[i]=1;
        for(int i=1;i<=n;i++) lst[s[i]-'a']=i,r+=f[s[i]-'a'],f[s[i]-'a']=0;
        for(int i=n;i>=1;i--) fst[s[i]-'a']=i;
        while(r){
            for(int i=25;i>=0;i--){
                if(f[i]) continue;
                int fl=1;
                for(int j=25;j>=0;j--) if(f[j]==0&&lst[j]<fst[i]) fl=0;
                if(fl){
                    //cout<<char('a'+i)<<endl;
                    printf("%c",'a'+i);
                    f[i]=1;
                    for(int j=0;j<26;j++)
                        if(f[j]==0){
                            for(int k=fst[i]+1;k<=n;k++)
                                if(s[k]==j+'a'){
                                    fst[j]=k;
                                    break;
                                }
                        }
                    r--;
                    break;
                }
            }
        }
        puts("");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp