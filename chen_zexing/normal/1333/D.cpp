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
vector <int> v[300005];
char s[3005];
int check(int n){
    for(int i=1;i<n;i++) if(s[i]=='R'&&s[i+1]=='L') return 1;
    return 0;
}
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n,k;
        cin>>n>>k;
        scanf("%s",s+1);
        int x=0,tot=0;
        while(check(n)){
            x++;
            for(int i=1;i<=n;i++){
                if(s[i]=='R'&&s[i+1]=='L'){
                    v[x].push_back(i);
                    tot++;
                }
            }
            for(int i=0;i<v[x].size();i++) s[v[x][i]]='L',s[v[x][i]+1]='R';
        }
        if(k<x||k>tot){
            puts("-1");
            continue;
        }
        int now=1,pos=0;
        while(k>x-now+1) {
            printf("1 %d\n", v[now][pos]);
            pos++, k--;
            if (pos >= v[now].size()) now++, pos = 0;
        }
        if(pos<v[now].size()){
            printf("%d ",v[now].size()-pos);
            for(int i=pos;i<v[now].size();i++) printf("%d ",v[now][i]);
            puts("");
            now++;
        }
        for(int i=now;i<=x;i++){
            printf("%d ",v[i].size());
            for(int j=0;j<v[i].size();j++) printf("%d ",v[i][j]);
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