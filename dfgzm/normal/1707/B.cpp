#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int i,j,k,n,m,a[maxn],b[maxn];
string S;
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;m=0;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        for(i=1;i<=n;i++)m+=(a[i]==0);
        for(int t=1;t<n;t++){
            for(i=max(t,m);i<=n;i++)b[i]=a[i]-a[i-1];
            for(i=max(t,m);i<=n;i++)a[i]=b[i];
            a[t]=0;
            while(m<=n && !a[m+1])++m;
            if(m>n)break;
            sort(a+m+1,a+1+n);
        }
        printf("%d\n",a[n]);
    }
}
/*
a1 a2 a3 a4
a2-a1 a3-a2 a4-a3
a3-2a2+a1 a4-2a3+a2
*/