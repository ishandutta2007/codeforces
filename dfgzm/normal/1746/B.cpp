#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k,n,m,a[maxn],u[maxn],s[maxn];
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(i=1;i<=n;i++)scanf("%d",&a[i]),u[i]=u[i-1]+(a[i]==1);
        s[n+1]=0;for(i=n;i>=1;i--)s[i]=s[i+1]+(a[i]==0);
        k=1e9;for(i=0;i<=n;i++)k=min(k,u[i]+max(0,s[i+1]-u[i]));
        printf("%d\n",k);
    }
}