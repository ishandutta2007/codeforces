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
int a[100000];
int main(){
    int i,j,k,n,cnt=0,mi=1000000;
    cin>>n>>k;
    for(i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0)cnt++;
        mi=min(mi,abs(a[i]));
    }
    if(k<cnt){
        int res=0;
        for(i=0;i<k;i++)a[i]=-a[i];
        for(i=0;i<n;i++)res+=a[i];
        printf("%d\n",res);
    }
    else{
        int res=0;
        for(i=0;i<n;i++)res+=abs(a[i]);
        if((k-cnt)%2==0){
            printf("%d\n",res);
        }
        else{
            printf("%d\n",res-mi*2);
        }
    }
    return 0;
}