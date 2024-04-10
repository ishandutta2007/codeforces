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
int a[4444],cnt[4444];
int dp[4444][4444],d[4444];
int dn,an;
int get(int x){return lower_bound(d,d+dn,x)-d;}
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
        d[i-1]=a[i];
    }
    sort(d,d+n);
    dn=unique(d,d+n)-d;
    for(i=0;i<dn;i++)dp[n+1][i]=-1;
    for(i=1;i<=n;i++){
        a[i]=get(a[i]);
        cnt[a[i]]++;
    }
    for(i=0;i<dn;i++)an=max(an,cnt[i]);
    for(i=n;i>0;i--){
        for(j=0;j<dn;j++)dp[i][j]=dp[i+1][j];
        dp[i][a[i]]=i;
    }
    for(i=0;i<dn;i++)
        for(j=0;j<dn;j++){
            //printf("[%d,%d]\n",i,j);
            if(i==j)continue;
            int now=1;
            int flag=0;
            int ha=0;
            while(now<=n){
                int next;
                if(flag)next=dp[now][i]+1;
                else next=dp[now][j]+1;
                if(next==0)break;
                ha++;
                flag^=1;
                now=next;
            }
            an=max(an,ha);
        }
    cout<<an<<endl;
    return 0;
}