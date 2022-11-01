#include<bits/stdc++.h>
using namespace std;

int n,q;
int s[100005];
int l[100005];
int r[100005];
pair<int,int> dp[100005][17];
int pw[17];

pair<int,int> dfs(int l,int c){
    if(c==0)return make_pair(0,s[l]);
    if(dp[l][c]!=make_pair(-1,-1))return dp[l][c];
    pair<int,int> s1=dfs(l,c-1);
    pair<int,int> s2=dfs(l+pw[c-1],c-1);
    int cs=int(s1.second+s2.second>=10)+s1.first+s2.first;
    int md=(s1.second+s2.second)%10;
    return dp[l][c]=make_pair(cs,md);
}

void init(){
    int c=1;
    for(int i=0;i<=16;i++){
        pw[i]=c;
        c*=2;
    }
}

int main(){

    init();

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",s+i);
        for(int j=0;j<=17;j++)dp[i][j]=make_pair(-1,-1);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d %d",l+i,r+i);
        int t=r[i]-l[i]+1;
        int c=0;
        while(t>1){
            t>>=1;
            c++;
        }
        printf("%d\n",dfs(l[i],c).first);
    }

    return 0;
}