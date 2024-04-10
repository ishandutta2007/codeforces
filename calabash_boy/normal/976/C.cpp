//
// Created by calabash_boy on 18-4-30.
//
#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+100;
pair<int,int> a[maxn];
int rk[maxn];
int n;
bool cmp(int xx,int yy){
    auto x = a[xx];
    auto y = a[yy];
    if (x.first<y.first||x.first==y.first&&x.second>y.second)return true;
    else return false;
}
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
        rk[i]=i;
    }
    sort(rk,rk+n,cmp);
    int maxR =-1;
    int ans1 = -1;
    for (int i=0;i<n;i++){
        if(maxR>=a[rk[i]].second){
            printf("%d %d\n",rk[i]+1,ans1+1);
            return 0;
        }
        if (maxR<a[rk[i]].second){
            maxR = a[rk[i]].second;
            ans1 = rk[i];
        }
    }
    printf("%d %d\n",-1,-1);
    return 0;
}