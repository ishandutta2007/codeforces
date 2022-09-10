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
#define SIZE 111
using namespace std;
struct Node{
    int end;
    map<char,Node*>ha;
    Node(){end=0;ha.clear();}
}*root,base[1001000];
int yo,K;
void dfs(Node* ptr,int de,int dp[]){
    map<char,Node*>::iterator it;
    //printf("--->>\n");
    for(it=ptr->ha.begin();it!=ptr->ha.end();it++){
        //printf("%c\n",it->first);
        int dp2[SIZE];
        memset(dp2,-1,sizeof(dp2));
        dp2[0]=0;
        dfs(it->second,de+1,dp2);
        for(int i=K;i>=0;i--){
            dp[i]=max(dp[i],dp2[i]);
            for(int j=1;j<i;j++){
                if(dp[j]>=0&&dp2[i-j]>=0)dp[i]=max(dp[i],dp[j]+dp2[i-j]+j*(i-j)*de);
            }
        }
    }
    //printf("<---\n");
    if(ptr->end){
        for(int i=K;i>0;i--){
            for(int j=1;j<=i&&j<=ptr->end;j++)if(dp[i-j]>=0)dp[i]=max(dp[i],dp[i-j]+de*((i-j)*j+j*(j-1)/2));
        }
    }
}
int main(){
    int i,j,k,n;
    root=&base[yo++];
    scanf("%d%d",&n,&K);
    for(i=0;i<n;i++){
        char s[666];
        scanf("%s",s);
        Node *ptr=root;
        for(j=0;s[j];j++){
            if(ptr->ha.count(s[j])==0){
                ptr->ha[s[j]]=&base[yo];
                ptr=&base[yo++];
            }
            else{
                ptr=ptr->ha[s[j]];
            }
        }
        ptr->end++;
    }
    int dp[SIZE];
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    dfs(root,0,dp);
    printf("%d\n",dp[K]);
    return 0;
}