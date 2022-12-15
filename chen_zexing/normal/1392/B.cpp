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
int a[200005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        long long k;
        cin>>n>>k;
        int mx=INT_MIN;
        k--;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]>mx) mx=a[i];
        }
        for(int i=1;i<=n;i++) a[i]=mx-a[i];
        if(k%2)
        {
            mx=INT_MIN;
            for(int i=1;i<=n;i++) mx=max(mx,a[i]);
            for(int i=1;i<=n;i++) printf("%d ",mx-a[i]);
            printf("\n");
        }
        else{
            for(int i=1;i<=n;i++) printf("%d ",a[i]);
            printf("\n");
        }
    }
    return 0;
}