/*
 * @Author: BilyHurington
 * @Date: 2021-02-28 21:42:38
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-02-28 21:46:45
 */
#include<bits/stdc++.h>
using namespace std;
int T,n,u,v,a[110];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&n,&u,&v);
        int minn=2e9,maxn=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            minn=min(a[i],minn);
            maxn=max(a[i],maxn);
        }
        if(minn==maxn) printf("%d\n",min(u+v,2*v));
        else{
            bool tag=1;
            for(int i=1;i<=n;i++){
                if(i>1&&abs(a[i]-a[i-1])>1) tag=0;
            }
            if(!tag) puts("0");
            else printf("%d\n",min(u,v));
        }
    }
    return 0;
}