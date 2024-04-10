/*
 * @Author: BilyHurington
 * @Date: 2020-09-30 22:35:11
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-09-30 23:12:07
 */
#include<bits/stdc++.h>
using namespace std;
int T,n,k,a[110];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(k==1){
            bool tag=1;
            for(int i=1;i<n;i++){
                if(a[i]!=a[i+1]){
                    tag=0;break;
                }
            }
            if(!tag) puts("-1");
            else puts("1");
            continue;
        }
        for(int i=n;i>=1;i--) a[i]-=a[i-1];
        int cnt=0;
        for(int i=1;i<=n;i++) if(a[i]) cnt++;
        if(a[1]&&cnt>1) cnt--;
        printf("%d\n",(int)ceil(1.0*cnt/(k-1)));
    }
    return 0;
}