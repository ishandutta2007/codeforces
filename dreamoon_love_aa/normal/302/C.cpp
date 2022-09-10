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
#define SIZE 500
int a[SIZE],used[SIZE],bfs[SIZE];
int main(){
    int i,j,k,n,ma,sum=0;
    scanf("%d",&n);
    for(i=0;i<n+n-1;i++){
        cin>>a[i];
        sum+=a[i];
    }
    bfs[0]=0;
    used[0]=1;
    for(i=0,j=1;i<j;i++){
        int x=bfs[i];
        for(k=0;k<=x&&k<=n;k++){
            if(n-k>n+n-1-x)continue;
            int ne=(x-k)+n-k;
            if(!used[ne]){
                used[ne]=1;
                bfs[j++]=ne;
            }
        }
    }
    ma=sum;
    sort(a,a+n+n-1);
    for(i=0;i<=n+n-1;i++){
        if(used[i])ma=max(ma,sum);
        sum-=a[i];
        sum+=-a[i];
    }
    cout<<ma<<endl;
    return 0;
}