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
    cin >> T;
    while (T--) {
        int n,a,b,now;
        scanf("%d%d%d",&n,&a,&b);
        int d;
        for(int i=1;i<=b-a;i++)
        {
            if((b-a)%i==0&&(b-a)/i+1<=n)
            {
                d=i;
                break;
            }
        }
        for(int i=a;i<=b;i+=d) printf("%d ",i);
        n-=((b-a)/d+1);
        now=a-d;
        while(n&&now>0){
            n--;
            printf("%d ",now);
            now-=d;
        }
        now=b+d;
        while(n){
            n--;
            printf("%d ",now);
            now+=d;
        }
        printf("\n");
    }
    return 0;
}