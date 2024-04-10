#include<bits/stdc++.h>
#define outY puts("YES")
#define outN puts("NO")
using namespace std;
const int maxn=100010;
int i,j,k,n,m,T,a[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(i=1;i<=m;i++)scanf("%d",&a[i]);
        if(m==1){outY;continue;}
        if(n==m){
            int is=0;
            for(i=0;i<m-1;i++)
                if(a[i+1]-a[i]>a[i+2]-a[i+1])is=1;
            if(is)outN;
            else outY;
        }else{
            int is=0;
            for(i=1;i<m-1;i++)
                if(a[i+1]-a[i]>a[i+2]-a[i+1])is=1;
            if(is || 1ll*(a[2]-a[1])*(n-m+1)<a[1])outN;
            else outY;
        }
    }
}