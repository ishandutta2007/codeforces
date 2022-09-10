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
int an[2][2];
#define MAX 1000000010
vector<int>xx,yy;
long long dis(long long x,long long a,long long m){
    return min(m-x,x+a-m);
}
int main(){
    int i,j,k,n,m,x,y,a,b,mi_x=MAX,mi_y=MAX,ma_x=MAX,ma_y=MAX;
    long long ma=0;
    cin>>n>>m>>x>>y>>a>>b;
    int gg=__gcd(a,b);
    a/=gg;
    b/=gg;
    k=min(n/a,m/b);
    a*=k;
    b*=k;
    xx.pb(0);
    if(n-a>=0)xx.pb(n-a);
    if(x-a/2>=0)xx.pb(x-a/2);
    if(x-a/2-1>=0)xx.pb(x-a/2-1);
    yy.pb(0);
    if(m-b>=0)yy.pb(m-b);
    if(y-b/2>=0)yy.pb(y-b/2);
    if(y-b/2-1>=0)yy.pb(y-b/2-1);
    for(i=0;i<xx.size();i++)
        for(j=0;j<yy.size();j++){
            if(xx[i]<=x&&x<=xx[i]+a&&yy[j]<=y&&y<=yy[j]+b&&yy[j]+b<=m&&xx[i]+a<=n){
                if(ma<dis(xx[i],a,x)+dis(yy[j],b,y)||(ma==dis(xx[i],a,x)+dis(yy[j],b,y)&&make_pair(xx[i],yy[j])<make_pair(mi_x,mi_y))){
                    ma=dis(xx[i],a,x)+dis(yy[j],b,y);
                    mi_x=xx[i];
                    mi_y=yy[j];
                    ma_x=xx[i]+a;
                    ma_y=yy[j]+b;
                }
            }
        }
    printf("%d %d %d %d\n",mi_x,mi_y,ma_x,ma_y);
    return 0;
}