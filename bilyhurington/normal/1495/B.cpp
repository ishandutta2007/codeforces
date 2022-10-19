/*
 * @Author: BilyHurington
 * @Date: 2021-03-10 20:05:26
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-03-10 21:00:01
 */
#include<bits/stdc++.h>
using namespace std;
int n,p[100010],Lsm[100010],Lbi[100010],Rsm[100010],Rbi[100010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&p[i]);
    p[0]=p[1];p[n+1]=p[n];
    for(int i=2;i<=n;i++){
        if(p[i-1]<p[i]) Lsm[i]=Lsm[i-1]+1,Lbi[i]=0;
        if(p[i-1]>p[i]) Lbi[i]=Lbi[i-1]+1,Lsm[i]=0;
    }
    for(int i=n-1;i>=1;i--){
        if(p[i+1]<p[i]) Rsm[i]=Rsm[i+1]+1,Rbi[i]=0;
        if(p[i+1]>p[i]) Rbi[i]=Rbi[i+1]+1,Rsm[i]=0;
    }
    int maxn=0;
    vector<int> max_pos;
    for(int i=1;i<=n;i++){
        if(maxn<=max(Lsm[i],Lbi[i])){
            maxn=max(Lsm[i],Lbi[i])+1;
            max_pos.clear();
        }
        if(maxn==max(Lsm[i],Lbi[i])+1) max_pos.push_back(i);
        // printf("%d %d %d %d\n",Lsm[i],Lbi[i],Rsm[i],Rbi[i]);
        // printf("%d\n",max(Lsm[i],Lbi[i])+1);
    }
    if(maxn==1){puts("0");return 0;}
    if(max_pos.size()>2){puts("0");return 0;}
    if(max_pos.size()==2){
        // printf("YES");
        int x=max_pos[0];
        if(p[x-1]>=p[x]||p[x+1]>=p[x]){puts("0");return 0;}
        if(max(Lsm[x],Lbi[x])==max(Rsm[x],Rbi[x])){
            if(maxn&1) puts("1");
            else puts("0");
            return 0;
        }
        puts("0");return 0;
    }
    puts("0");
    return 0;
}