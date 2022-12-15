#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--){
        long long x,y;
        long long c[7];
        scanf("%lld%lld",&x,&y);
        for(int i=1;i<=6;i++) scanf("%lld",&c[i]);
        for(int i=2;i<=5;i++) c[i]=min(c[i],c[i-1]+c[i+1]);
        c[1]=min(c[2]+c[6],c[1]);c[6]=min(c[5]+c[1],c[6]);
        swap(x,y);
        if(x>=0&&y<=0) printf("%lld\n",c[2]*x+c[3]*(-y));
        else if(x<=0&&y<=0&&x>=y){
            x=abs(x);y=abs(y);
            printf("%lld\n",c[4]*min(x,y)+c[3]*(y-x));
        }
        else if(x<=0&&y<=0&&x<=y){
            x=abs(x);y=abs(y);
            printf("%lld\n",c[5]*(x-y)+c[4]*y);
        }
        else if(x<=0&&y>=0){
            printf("%lld\n",c[5]*(-x)+c[6]*y);
        }
        else if(x>=0&&y>=0&&y>=x){
            printf("%lld\n",c[1]*x+c[6]*(y-x));
        }
        else if(x>=0&&y>=0&&x>=y){
            printf("%lld\n",c[1]*y+c[2]*(x-y));
        }
    }
    return 0;
}