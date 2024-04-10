#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#define LL long long
#define MAX 100005

using namespace std;
int a[100005],ans[100005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int t=0;
        for(int i=1;i<=n;i++){
            if(a[i]*2<k) ans[i]=0;
            else if(a[i]*2>k) ans[i]=1;
            else{
                ans[i]=t;
                t=1-t;
            }
        }
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}