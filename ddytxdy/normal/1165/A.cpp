#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+50;
int n,x,y,a[N],ans;
int main(){
    scanf("%d%d%d",&n,&x,&y);
    for(int i=1;i<=n;i++)scanf("%1d",&a[i]);
    for(int i=n-x+1;i<=n;i++){
        if(i==n-y&&a[i]==0)ans++;
        if(i!=n-y&&a[i]==1)ans++;
    }
    printf("%d",ans);
    return 0;
}