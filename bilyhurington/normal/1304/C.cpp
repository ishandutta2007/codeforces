/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-02-13 19:21:04
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int q,n,m,t[110],l[110],h[110];
int main(){
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        long long ls=m,rs=m;
        bool pd=1;
        for(int i=1;i<=n;i++){
            scanf("%d %d %d",&t[i],&l[i],&h[i]);
            ls-=t[i]-t[i-1];
            rs+=t[i]-t[i-1];
            ls=max(ls,(long long)l[i]);
            rs=min(rs,(long long)h[i]);
            if(ls>rs){pd=0;}
        }
        if(pd) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}