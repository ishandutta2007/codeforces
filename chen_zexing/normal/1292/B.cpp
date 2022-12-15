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
long long x[1005],y[1005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        long long x0,y0,ax,ay,bx,by,xs,ys,t;
        cin>>x0>>y0>>ax>>ay>>bx>>by;
        cin>>xs>>ys>>t;
        x[0]=x0,y[0]=y0;
        int cnt=0;
        for(int i=1;x[i-1]<=xs+t&&y[i-1]<=ys+t;i++){
            x[i]=x[i-1]*ax+bx;
            y[i]=y[i-1]*ay+by;
            cnt++;
        }
        int ans=0;
        for(int i=0;i<=cnt;i++){
            long long now=0,xx=xs,yy=ys;
            for(int j=i;now<=t;j++){
                now+=abs(x[j]-xx)+abs(y[j]-yy);
                xx=x[j],yy=y[j];
                if(now>t) break;
                ans=max(ans,j-i+1);
            }
            now=0,xx=xs,yy=ys;
            for(int j=i;now<=t&&j>=0;j--){
                now+=abs(x[j]-xx)+abs(y[j]-yy);
                xx=x[j],yy=y[j];
                if(now>t) break;
                ans=max(ans,i-j+1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}