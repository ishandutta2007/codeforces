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
char s[105][105];
char ans[105][105];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,m,k,cnt=0;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(s[i][j]=='R')
                    cnt++;
        int t1,t2,b=cnt/k;
        t2=cnt-b*k,t1=k-t2;
        //cout<<t1<<" "<<t2<<" "<<b<<endl;
        int now=1,c=0;
        for(int i=1;i<=n;i++){
            if(i%2){
                for(int j=1;j<=m;j++)
                {
                    if(now<=26) ans[i][j]='a'+now-1;
                    else if(now<=52) ans[i][j]='A'+now-27;
                    else ans[i][j]='0'+now-53;
                    if(s[i][j]=='R'){
                        c++;
                        if((now<=t1&&c==b||now>t1&&c==b+1)&&now<k){
                            c=0;
                            now++;
                        }
                    }
                }
            }
            else{
                for(int j=m;j>=1;j--){
                    if(now<=26) ans[i][j]='a'+now-1;
                    else if(now<=52) ans[i][j]='A'+now-27;
                    else ans[i][j]='0'+now-53;
                    if(s[i][j]=='R'){
                        c++;
                        if((now<=t1&&c==b||now>t1&&c==b+1)&&now<k){
                            c=0;
                            now++;
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=m;j++)
                printf("%c",ans[i][j]);
    }
    return 0;
}