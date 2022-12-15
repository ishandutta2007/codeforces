#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#define LL long long
#define MAX 100005

using namespace std;
int a[1005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,k;
        int mn=INT_MAX,p;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(mn>a[i]){
                mn=a[i];
                p=i;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(i==p) continue;
            ans+=(k-a[i])/mn;
        }
        printf("%d\n",ans);
    }
    return 0;
}