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
        int n,t,sum=0,mx=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&t);
            sum+=t;
            mx=max(mx,t);
        }
        if(mx*2>sum||sum%2) printf("T\n");
        else printf("HL\n");
    }
    return 0;
}