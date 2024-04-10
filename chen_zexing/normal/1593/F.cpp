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
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int sel[45][85][45][45];
struct node{
    int dif,ra,rb;
}from[45][85][45][45];
char s[45];
int c[45];
int main() {
    int T = 1;
    cin >> T;
    while(T--){
        int n,a,b;
        cin>>n>>a>>b;
        scanf("%s",s+1);
        memset(sel,-1,sizeof(sel)),memset(from,-1,sizeof(from));
        sel[0][40][0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=40-i+1;j<=40+i-1;j++)
                for(int k=0;k<a;k++)
                    for(int l=0;l<b;l++)
                        if(sel[i-1][j][k][l]!=-1){
                            //cout<<i-1<<" "<<j<<" "<<l<<" "<<l<<endl;
                            sel[i][j+1][(k*10+s[i]-'0')%a][l]=1,from[i][j+1][(k*10+s[i]-'0')%a][l]=node{j,k,l};
                            sel[i][j-1][k][(l*10+s[i]-'0')%b]=2,from[i][j-1][k][(l*10+s[i]-'0')%b]=node{j,k,l};
                        }
        }
        int mn=INT_MAX;
        node ans;
        for(int i=40-n+1;i<=40+n-1;i++) if(sel[n][i][0][0]!=-1){
                if(mn>abs(40-i)) mn=abs(40-i),ans=node{i,0,0};
            }
        if(mn==INT_MAX){
            puts("-1");
            continue;
        }
        for(int i=n;i>=1;i--){
            c[i]=sel[i][ans.dif][ans.ra][ans.rb];
            ans=from[i][ans.dif][ans.ra][ans.rb];
        }
        for(int i=1;i<=n;i++) printf("%c",c[i]==1?'R':'B');
        puts("");
    }
    return 0;
}
//
/// 
//01
//