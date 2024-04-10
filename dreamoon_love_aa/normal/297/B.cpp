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
#define SIZE 100010
int a[SIZE],b[SIZE];
int main(){
    int i,j,k,n,m;
    scanf("%d%d%d",&n,&m,&k);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<m;i++)scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+m);
    for(i=0,j=0;i<n;i++){
        while(j<m&&b[j]<a[i])j++;
        if(n-i>m-j){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}