#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
int a[100];
int main(){
    int i,j,k,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    int now=10,an1=0,an2=0;
    for(i=0;i<n;i++){
        now+=a[i];
        if(now>720)break;
        an1++;
        an2+=max(0,now-360);
    }
    printf("%d %d\n",an1,an2);
    return 0;
}