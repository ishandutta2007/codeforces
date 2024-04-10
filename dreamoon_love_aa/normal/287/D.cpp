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
int a[2000011];
int main(){
    int i,j,k,n,now=1;
    cin>>n;
    for(i=1;i<=n;i++)a[i]=i;
    for(i=2;i<=n;i++,now++){
        int next;
        for(j=0;j<=n;j+=i)swap(next,a[now+j]);
        if(n%i)swap(next,a[now+n]);
    }
    for(i=0;i<n;i++)printf("%d ",a[now+i]);
    puts("");
    return 0;
}