#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
char s[105][1005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int c,h,t;
        scanf("%d%d%d",&h,&c,&t);
        if(t*2<=c+h) printf("2\n");
        else{
            double k1=ceil((double(h)-t)/(2.0*t-c-h));
            double k2=k1-1;
            //cout<<k1<<" "<<k2<<endl;
            if(t==h) printf("1\n");
            else if((k2*c+k2*h+h)/(2*k2+1)-double(t)<=double(t)-(k1*c+k1*h+h)/(2*k1+1)) printf("%d\n",2*int(k2)+1);
            else printf("%d\n",2*int(k1)+1);
        }
    }
    return 0;
}