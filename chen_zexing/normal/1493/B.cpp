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
int c[15]={0,1,5,-1,-1,2,-1,-1,8,-1};
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int h,m;
        string s;
        scanf("%d%d",&h,&m);
        cin>>s;
        int a=(s[0]-'0')*10+s[1]-'0';
        int b=(s[3]-'0')*10+s[4]-'0';
        int aa=a,bb=b;
        int mn1=0,mn2=0;
        while(1){
            if(b>=m) b-=m,a++;
            if(a>=h) a-=h;
            int a1=a/10,a2=a%10,b1=b/10,b2=b%10;
            a1=c[a1],a2=c[a2],b1=c[b1],b2=c[b2];
            if(a1==-1||a2==-1||b1==-1||b2==-1){
                b++;
                mn1++;
                continue;
            }
            if(b2*10+b1>=h||a2*10+a1>=m){
                b++;
                mn1++;
                continue;
            }
            break;
        }
        if(a<10) printf("0");
        cout<<a<<":";
        if(b<10) printf("0");
        cout<<b<<endl;
    }
    return 0;
}
//
/// 