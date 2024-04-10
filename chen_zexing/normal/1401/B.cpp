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
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int a1,b1,c1;
        int a2,b2,c2;
        scanf("%d%d%d",&c1,&b1,&a1);
        scanf("%d%d%d",&c2,&b2,&a2);
        int ans=0;
        ans+=min(a1,b2)*2;
        a1-=min(a1,b2);
        if(a2>a1+c1) ans-=(a2-a1-c1)*2;
        printf("%d\n",ans);
    }
    return 0;
}