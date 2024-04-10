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
char s[100005];
int nxt[100005][26];
char a[255],b[255],c[255];
int dp[255][255][255];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,q,pa=0,pb=0,pc=0;
        cin>>n>>q;
        scanf("%s",s+1);
        for(int i=0;i<26;i++) nxt[n+1][i]=nxt[n+2][i]=n+1;
        for(int i=n;i>=1;i--){
            for(int j=0;j<26;j++) nxt[i][j]=nxt[i+1][j];
            nxt[i][s[i]-'a']=i;
        }
        for(int i=0;i<=250;i++)
            for(int j=0;j<=250;j++)
                for(int k=0;k<=250;k++)
                    dp[i][j][k]=n+1;
        dp[0][0][0]=0;
        for(int i=1;i<=q;i++){
            char type='?';
            while(type!='-'&&type!='+') scanf("%c",&type);
            if(type=='+'){
                int id;
                char cc='-';
                scanf("%d",&id);
                while(cc<'a'||cc>'z') scanf("%c",&cc);
                if(id==1){
                    a[++pa]=cc;
                    for(int j=0;j<=pb;j++)
                        for(int k=0;k<=pc;k++){
                            dp[pa][j][k]=min(dp[pa][j][k],nxt[dp[pa-1][j][k]+1][a[pa]-'a']);
                            if(j) dp[pa][j][k]=min(dp[pa][j][k],nxt[dp[pa][j-1][k]+1][b[j]-'a']);
                            if(k) dp[pa][j][k]=min(dp[pa][j][k],nxt[dp[pa][j][k-1]+1][c[k]-'a']);
                        }
                }
                else if(id==2){
                    b[++pb]=cc;
                    for(int j=0;j<=pa;j++)
                        for(int k=0;k<=pc;k++){
                            dp[j][pb][k]=min(dp[j][pb][k],nxt[dp[j][pb-1][k]+1][b[pb]-'a']);
                            if(j) dp[j][pb][k]=min(dp[j][pb][k],nxt[dp[j-1][pb][k]+1][a[j]-'a']);
                            if(k) dp[j][pb][k]=min(dp[j][pb][k],nxt[dp[j][pb][k-1]+1][c[k]-'a']);
                        }
                }
                else{
                    c[++pc]=cc;
                    for(int j=0;j<=pa;j++)
                        for(int k=0;k<=pb;k++){
                            dp[j][k][pc]=min(dp[j][k][pc],nxt[dp[j][k][pc-1]+1][c[pc]-'a']);
                            if(j) dp[j][k][pc]=min(dp[j][k][pc],nxt[dp[j-1][k][pc]+1][a[j]-'a']);
                            if(k) dp[j][k][pc]=min(dp[j][k][pc],nxt[dp[j][k-1][pc]+1][b[k]-'a']);
                        }
                }
            }
            else{
                int id;
                scanf("%d",&id);
                if(id==1){
                    for(int j=0;j<=pb;j++)
                        for(int k=0;k<=pc;k++)
                            dp[pa][j][k]=n+1;
                    pa--;
                }
                else if(id==2){
                    for(int j=0;j<=pa;j++)
                        for(int k=0;k<=pc;k++)
                            dp[j][pb][k]=n+1;
                    pb--;
                }
                else{
                    for(int j=0;j<=pa;j++)
                        for(int k=0;k<=pb;k++)
                            dp[j][k][pc]=n+1;
                    pc--;
                }
            }
            /*
            for(int j=0;j<=pa;j++)
                for(int k=0;k<=pb;k++)
                    for(int l=0;l<=pc;l++)
                        cout<<dp[j][k][l]<<" "<<j<<" "<<k<<" "<<l<<endl;
            puts(""),puts("");
             */
            puts(dp[pa][pb][pc]<=n?"YES":"NO");
        }
    }
    return 0;
}
//
/// 
//01
//