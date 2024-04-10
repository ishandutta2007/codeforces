/*
 * @Author: BilyHurington
 * @Date: 2020-10-17 21:05:04
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-10-17 21:59:18
 */ 
#include<bits/stdc++.h>
using namespace std;
int n,len[500010],st[500010][3],tot;
long long st_sum;
char s[500010];
void upt(int L){
    for(int i=tot;i>=1&&st[i][2]<L;i--){
        st_sum+=1ll*(st[i][1]-st[i][0]+1)*(L-st[i][2]);
        st[i][2]=max(st[i][2],L);
    }
    while(tot>1&&st[tot][2]==st[tot-1][2]){
        st[tot-1][1]=st[tot][1];
        st[tot][0]=st[tot][1]=st[tot][2]=0;
        tot--;
    }
}
void ins(int pos,int L){
    upt(L);++tot;
    st[tot][0]=st[tot][1]=pos;st[tot][2]=L;
    st_sum+=L;
}
int main(){
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='0') len[i]=0;
        else len[i]=len[i-1]+1;
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='0'){
            for(int j=i-len[i-1];j<=i;j++){
                ins(j,i-j);
            }
            ans+=st_sum;
        }
        else{
            upt(len[i]);
            ans+=st_sum+1ll*(len[i]+1)*len[i]/2;
        }
        // printf("ID: %d\n",i);
        // for(int j=1;j<=tot;j++){
        //     printf("%d %d %d\n",st[j][0],st[j][1],st[j][2]);
        // }
        // printf("SUM %lld ANS: %lld\n",st_sum,ans);
    }
    printf("%lld",ans);
    return 0;
}