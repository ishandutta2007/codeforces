#include <stdio.h>
#include<iostream>
#include<string>
#include <algorithm>
#include <string.h>
#include <vector>
#include <cmath>
#define LL long long
#define MAX 100005

using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--){
        int ans=0,n;
        scanf("%d",&n);
        int a1=sqrt(n),a2=sqrt(n)+1,a3=sqrt(n)-1;
        ans=min(a1-1+n/a1-1+(n%a1>0),a2-1+n/a2-1+(n%a2>0));
        if(a3) ans=min(ans,a3-1+n/a3-1+(n%a3>0));
        printf("%d\n",ans);
    }
    return 0;
}