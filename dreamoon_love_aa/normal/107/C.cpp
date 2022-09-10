#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;
bool over[16][16],used[16];
int an[16],n,one[65536];
long long dp[65536];
long long Count(int know){
    int ini=0,i,j,k,p[16],pn=0,seat;
    for(i=0;i<n;i++)
        if(!used[i])p[pn++]=i;
    for(i=0;i<know;i++)ini|=1<<(n-1-i);
    dp[ini]=1;
    for(i=ini+1;i<(1<<n);i++){
        dp[i]=0;
        int now=p[one[i]-1-know];
        for(seat=n-1,j=1;seat>=know;j<<=1,seat--){
            if(j&i){
                for(k=0;k<n-know;k++){
                    if(((1<<k)&i)&&(1<<k)!=j){
                        if(over[seat][n-k-1])break;
                    }
                }
                if(k<n-know)continue;
                for(k=0;k<know;k++){
                    if(over[seat][k]&&now>an[k])break;
                    if(over[k][seat]&&an[k]>now)break;
                }
                if(k<know)continue;
                dp[i]+=dp[i-j];
            }
        }
    }
    return dp[(1<<n)-1];
}
int main(){
    int m,x,y,i,j,k;
    long long Y,tmp;
    for(i=1;i<65536;i++)one[i]=one[i-(i&-i)]+1;
    cin>>n>>Y>>m;
    Y-=2000;
    while(m--){
        cin>>x>>y;
        x--,y--;
        over[x][y]=1;
    }
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(over[i][k]&&over[k][j])over[i][j]=true;
    for(i=0;i<n;i++)
        if(over[i][i])break;
    tmp=Count(0);
    if(i<n||tmp<Y){
        cout<<"The times have changed\n";
        return 0;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(used[j])continue;
            for(k=0;k<i;k++){
                if(over[i][k]&&j>an[k])break;
                if(over[k][i]&&an[k]>j)break;
            }
            if(k<i)continue;
            used[j]=1;
            an[i]=j;
            tmp=Count(i+1);
            if(tmp>=Y)break;
            used[j]=0;
            Y-=tmp;
        }
    }

    for(i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<(an[i]+1);
    }
    cout<<endl;
    return 0;
}