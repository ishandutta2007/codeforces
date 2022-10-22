/*
 * @Author: BilyHurington
 * @Date: 2020-05-31 22:36:40
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-06-01 00:21:01
 */ 
#include<bits/stdc++.h>
using namespace std;
int T,n,k;
void solve(){
    int num=0;
    scanf("%d %d",&n,&k);
    for(int i=1,x,y;i<n;i++){
        scanf("%d %d",&x,&y);
        num+=(x==k)+(y==k);
    }
    if(n%2==0||num<=1) printf("Ayush\n");
    else printf("Ashish\n");
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}