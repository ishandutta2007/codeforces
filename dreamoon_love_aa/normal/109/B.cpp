#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>lucky;
void dfs(long long x){
    if(x>=1000000000)return;
    if(x)lucky.push_back(x);
    dfs(x*10+4);
    dfs(x*10+7);
}
long long Inter(long long x1,long long y1,long long x2,long long y2){
    return max(min(y1,y2)-max(x1,x2)+1,0ll);
}
main(){
    int i;
    dfs(0);
    lucky.push_back(0);
    lucky.push_back(1000000010);
    sort(lucky.begin(),lucky.end());
    long long pl,pr,vl,vr,k,X=0,Y=0;
    cin>>pl>>pr>>vl>>vr>>k;
    Y=(vr-vl+1)*(pr-pl+1);
    for(i=1;i+k<lucky.size();i++){
        X+=Inter(pl,pr,lucky[i-1]+1,lucky[i])*Inter(vl,vr,lucky[i+k-1],lucky[i+k]-1);
        X+=Inter(vl,vr,lucky[i-1]+1,lucky[i])*Inter(pl,pr,lucky[i+k-1],lucky[i+k]-1);
        if(k==1)X-=Inter(vl,vr,lucky[i],lucky[i])*Inter(pl,pr,lucky[i],lucky[i]);
    }
    printf("%.12lf\n",X*1./Y);
}