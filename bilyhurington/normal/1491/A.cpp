/*
 * @Author: BilyHurington
 * @Date: 2021-02-28 21:36:55
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-02-28 21:39:13
 */
#include<bits/stdc++.h>
using namespace std;
int n,q,a[100010];
int main(){
    scanf("%d %d",&n,&q);
    int cnt[2]={};
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
    for(int ti=1,x,y;ti<=q;ti++){
        scanf("%d %d",&x,&y);
        if(x==1) cnt[a[y]]--,a[y]^=1,cnt[a[y]]++;
        else{
            if(y<=cnt[1])puts("1");
            else puts("0");
        }
    }
    return 0;
}