/*
 * @Author: BilyHurington
 * @Date: 2021-03-10 20:05:26
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-03-10 20:13:07
 */
#include<bits/stdc++.h>
using namespace std;
int T,n;
double X[100010],Y[100010];
void solve(){
    int nx=0,ny=0;
    scanf("%d",&n);
    for(int i=1,x,y;i<=2*n;i++){
        scanf("%d %d",&x,&y);
        if(!x) Y[++ny]=fabs(y);
        else X[++nx]=fabs(x);
    }
    sort(X+1,X+n+1);
    sort(Y+1,Y+n+1);
    double ans=0;
    for(int i=1;i<=n;i++) ans+=sqrt(X[i]*X[i]+Y[i]*Y[i]);
    printf("%.15lf\n",ans);
}
int main(){
    scanf("%d",&T);while(T--) solve();
    return 0;
}