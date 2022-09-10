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
bool locate(long long n,long long m,long long x,long long y,long long a,long long b){
    long long k=1000000000;
    if(a%2==0)
        k=min(x/(a/2),(n-x)/(a/2));
    else
        k=min((x*2-1)/a,(n*2-x*2+1)/a);
    if(b%2==0)
        k=min(k,min(y/(b/2),(m-y)/(b/2)));
    else
        k=min(k,min((y*2-1)/b,(m*2-y*2+1)/b));
    if(k==0)return 0;
    int x1,y1,x2,y2;
    if(a%2==0){
        x1=x-a/2*k;
        x2=x+a/2*k;
    }
    else{
        x1=(x*2-1-a)/2;
        x2=(n*2-x*2+1+a)/2;
    }
    if(b%2==0){
        y1=y-b/2*k;
        y2=y+b/2*k;
    }
    else{
        y1=(y*2-1-b)/2;
        y2=(m*2-y*2+1+b)/2;
    }
    printf("%d %d %d %d\n",x1,y1,x2,y2);
    return 1;
}
int main(){
    int i,j,k,n,m,x,y,a,b,mi_x=MAX,mi_y=MAX,ma_x=MAX,ma_y=MAX;
    long long ma=0;
    cin>>n>>m>>x>>y>>a>>b;
    int gg=__gcd(a,b);
    a/=gg;
    b/=gg;
    //if(locate(n,m,x,y,a,b))return 0;
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