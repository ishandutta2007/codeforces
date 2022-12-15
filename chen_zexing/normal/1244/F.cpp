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
int f[200005];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n,k;
        cin>>n>>k;
        scanf("%s",s);
        memset(f,-1,sizeof(f));
        queue <int> q;
        for(int i=0;i<n;i++){
            int l=(i+n-1)%n,r=(i+n+1)%n;
            if(s[l]==s[i]||s[r]==s[i]){
                f[i]=0;
                q.push(i);
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            int l=(x+n-1)%n,r=(x+n+1)%n;
            if(f[l]==-1){
                f[l]=f[x]+1;
                q.push(l);
            }
            if(f[r]==-1){
                f[r]=f[x]+1;
                q.push(r);
            }
        }
        for(int i=0;i<n;i++){
            if(f[i]<k&&f[i]!=-1){
                if(f[i]%2){
                    if(s[i]=='B') printf("W");
                    else printf("B");
                }
                else{
                    printf("%c",s[i]);
                }
            }
            else{
                if(k%2){
                    if(s[i]=='B') printf("W");
                    else printf("B");
                }
                else{
                    printf("%c",s[i]);
                }
            }
        }
    }
    return 0;
}