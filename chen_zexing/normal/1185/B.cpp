#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
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
#define li __int128_t
#define ull unsigned long long
using namespace std;
char s[1000005],t[1000005];
struct node{
    int t,cnt;
};
vector <node> vs,vt;
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        scanf("%s",s+1);
        scanf("%s",t+1);
        vs.clear(),vt.clear();
        int ls=strlen(s+1),lt=strlen(t+1),cnt=0,type=0;
        for(int i=1;i<=ls+1;i++){
            if(i==ls+1) vs.push_back(node{type,cnt});
            else{
                if(i==1||s[i]!=s[i-1]){
                    if(i!=1) vs.push_back(node{type,cnt});
                    cnt=1,type=s[i]-'a';
                }
                else cnt++;
            }
        }
        cnt=0;
        for(int i=1;i<=lt+1;i++){
            if(i==lt+1) vt.push_back(node{type,cnt});
            else{
                if(i==1||t[i]!=t[i-1]){
                    if(i!=1) vt.push_back(node{type,cnt});
                    cnt=1,type=t[i]-'a';
                }
                else cnt++;
            }
        }
        int f=1;
        if(vs.size()!=vt.size()){
            puts("NO");
            continue;
        }
        for(int i=0;i<vs.size();i++) if(vs[i].cnt>vt[i].cnt||vs[i].t!=vt[i].t) f=0;
        puts(f?"YES":"NO");
    }
    return 0;
}
//
/// 
//01
//