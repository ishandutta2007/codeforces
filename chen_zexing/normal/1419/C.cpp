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
int a[1005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,x,sum=0,f=1,f2=0;
        cin>>n>>x;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]!=x) f=0;
            if(a[i]==x) f2=1;
            sum+=a[i];
        }
        if(f) printf("0\n");
        else if(x*n==sum||f2) printf("1\n");
        else printf("2\n");
    }
    return 0;
}