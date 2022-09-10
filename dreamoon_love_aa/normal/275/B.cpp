#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
char s[110][110];
int ll[110],rr[100],n,m,used[111][111],tt;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
bool Out(int x,int y){return x<0||y<0||x>=n||y>=m;}
void go2(int x,int y,int &cnt){
    int i,j;
    for(i=0;i<4;i++){
        for(j=0;!Out(x+dx[i]*j,y+dy[i]*j)&&s[x+dx[i]*j][y+dy[i]*j]=='B';j++){
            if(used[x+dx[i]*j][y+dy[i]*j]!=tt){
                used[x+dx[i]*j][y+dy[i]*j]=tt;
                cnt++;
            }
        }
    }
}
int go(int x,int y){
    int i,j,cnt=0;
    tt++;
    for(i=0;i<4;i++){
        for(j=0;!Out(x+dx[i]*j,y+dy[i]*j)&&s[x+dx[i]*j][y+dy[i]*j]=='B';j++){
            go2(x+dx[i]*j,y+dy[i]*j,cnt);
        }
    }
    return cnt;
}
int main(){
    int i,j,k,cnt=0;
    cin>>n>>m;
    for(i=0;i<n;i++){
        scanf("%s",s[i]);
        for(j=0;j<m;j++)
            cnt+=(s[i][j]=='B');
    }
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            if(s[i][j]=='B'){
                if(go(i,j)!=cnt){
                    puts("NO");
                    return 0;
                }
            }
        }
    puts("YES");
    return 0;
}