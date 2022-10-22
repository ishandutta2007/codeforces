#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int i,j,k,n,m,T,a[maxn],b[maxn];
int A[maxn],B[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=n;i++)scanf("%d",&b[i]);
        int x=1;
        for(i=1;i<=n;i++)if(b[i]<b[x])x=i;
        for(i=1;i<=n;i++)A[i]=a[(i+x+n-2)%n+1];
        for(i=1;i<=n;i++)B[i]=b[(i+x+n-2)%n+1];
        for(i=1;i<=n;i++)if(A[i]>B[i])x=0;
        if(!x)puts("NO");
        else{
            A[1]=B[1];
            for(i=n;i>=2;i--)
                if(A[i]==B[i] || B[i]<=A[i%n+1]+1)A[i]=B[i];
                else x=0;
            if(!x)puts("NO");
            else puts("YES");
        }
    }
}