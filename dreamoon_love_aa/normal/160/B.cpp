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
int a[2][200];
int main(){
    int i,j,k,n;
    string str;
    cin>>n>>str;
    for(i=0;i<n;i++)a[0][i]=str[i]-'0',a[1][i]=str[n+i]-'0';
    sort(a[0],a[0]+n);
    sort(a[1],a[1]+n);
    for(i=0;i<n;i++){
        if(a[0][i]<=a[1][i])break;
    }
    if(i==n){
        puts("YES");
        return 0;
    }
    for(i=0;i<n;i++){
        if(a[0][i]>=a[1][i])break;
    }
    if(i==n){
        puts("YES");
        return 0;
    }
    puts("NO");
    return 0;
}