#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
const int maxn=1e5+5;

set<int>r[maxn];
set<int>c[maxn];

int main(){
    long long n,m,k;
    scanf("%lld%lld%lld",&n,&m,&k);
    long long ans=0;
    for(int i=1;i<=k;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        r[x].insert(y);
        c[y].insert(x);
    }
    for(int i=1;i<=n;i++){
        r[i].insert(m+1);
        r[i].insert(0);
    }
    for(int i=1;i<=m;i++){
        c[i].insert(n+1);
        c[i].insert(0);
    }
    int x_max,x_min,y_max,y_min,dir,xn,yn;
    x_max=n,x_min=1,y_max=m,y_min=1,dir=0,xn=1,yn=1;
    int st=1;
    while(1){
        /* debug(xn);
         debug(yn);
         debug(dir);*/
        if(dir==0){
            int yc=(*(r[xn].lower_bound(yn)))-1;
            yc=min(yc,y_max);
            x_min=xn+1;
            if(yn==yc&&(!st)){
                break;
            }
            else{
                ans+=(yc-yn);
                yn=yc;
            }
        }
        else if(dir==1){
            int xc=(*(c[yn].lower_bound(xn)))-1;
            xc=min(xc,x_max);
            y_max=yn-1;
            if(xn==xc){
                break;
            }
            else{
                ans+=(xc-xn);
                xn=xc;
            }
        }
        else if(dir==2){
            int yc=(*(--r[xn].lower_bound(yn)))+1;
            yc=max(yc,y_min);
            x_max=xn-1;
            if(yn==yc){
                break;
            }
            else{
                ans+=(yn-yc);
                yn=yc;
            }
        }
        else if(dir==3){
            int xc=(*(--c[yn].lower_bound(xn)))+1;//debug(xc);
            xc=max(xc,x_min);

            y_min=yn+1;
            if(xn==xc){
                break;
            }
            else{
                ans+=(xn-xc);
                xn=xc;
            }
        }
        st=0;
        dir=(dir+1)%4;// debug(ans);
    }

    if(ans+k+1==n*m)printf("Yes\n");
    else printf("No\n");
    return 0;
};