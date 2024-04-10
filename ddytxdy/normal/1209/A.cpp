#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,a[N],num;bool vis[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)if(!vis[i]){
        num++;
        for(int j=i;j<=n;j++)if(a[j]%a[i]==0)vis[j]=1;
    }
    printf("%d\n",num);
    return 0;
}