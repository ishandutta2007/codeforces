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
int a[16],n,have[4][4],sum,ver[4];
bool used[16];
map<int,int>H;
void over(){
    int i,j;
    for(i=0;i<n;i++,puts(""))
        for(j=0;j<n;j++){
            if(j)printf(" ");
            printf("%d",have[i][j]);
        }
    exit(0);
}
void dfs(int x,int y,int v){
    //printf("(%d,%d,%d)\n",x,y,v);
    if(y==n-1){
        if(!H.count(sum-v)||H[sum-v]==0)return;
        H[sum-v]--;
        have[x][y]=sum-v;
        if(x==n-2){
            int tmp=0;
            for(int i=0;i<n-1;i++)tmp+=have[i][i];
            if(H.count(sum-tmp)&&H[sum-tmp]>0){
                have[n-1][n-1]=sum-tmp;
                over();
            }
        }
        dfs(x+1,0,0);
        H[sum-v]++;
        return;
    }
    for(map<int,int>::iterator it=H.begin();it!=H.end();it++){
        bool fa=false,fa2=false;
        if(it->second==0)continue;
        have[x][y]=it->first;
        ver[y]+=it->first;
        it->second--;
        if(x==n-2){
            if(y==1){
                int tmp=0;
                for(int i=0;i<n-1;i++)tmp+=have[i][0]-have[i][n-1-i];
                //printf("[%d]\n",tmp);
                if(tmp)fa2=1;
            }
            if(!H.count(sum-ver[y])||!H[sum-ver[y]])fa=1;
            else{
                //if(x==1&&y==1){
                //    for(int i=0;i<n;i++,puts(""))
                //        for(int j=0;j<n;j++)printf("%d ",have[i][j]);
                //}
                have[n-1][y]=sum-ver[y];
                H[sum-ver[y]]--;
            }
        }
        if(!fa&&!fa2){
            dfs(x,y+1,it->first+v);
        }
        if(x==n-2&&!fa)H[sum-ver[y]]++;
        ver[y]-=it->first;
        it->second++;
    }
}
int main(){
    //srand(514);
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n*n;i++){scanf("%d",&a[i]);sum+=a[i];H[a[i]]++;}
    //for(i=1;i<n;i++)swap(a[(rand())%(i+1)],a[i]);
    sum/=n;
    printf("%d\n",sum);
    if(n==1){
        printf("%d\n",a[0]);
        return 0;
    }
    else if(n==2){
        for(i=0;i<2;i++)
            printf("%d %d\n",a[0],a[0]);
        return 0;
    }
    else{
        dfs(0,0,0);
    }
    return 0;
}