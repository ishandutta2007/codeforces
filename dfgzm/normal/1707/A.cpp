#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int i,j,k,n,m,a[maxn];
string S;
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        if(m>=n)for(i=1;i<=n;i++)putchar('1');
        else{
            int L=1,R=n,Ans=0;
            while(L<=R){
                int Mid=L+R>>1;
                int k=m;
                for(i=Mid;i<=n;i++)if(k<a[i])--k;
                if(k>=0)R=Mid-1;
                else L=Mid+1;
            }
            k=R+1;
            for(i=1;i<k;i++)if(a[i]<=m)putchar('1');else putchar('0');
            for(i=k;i<=n;i++)putchar('1');
        }puts("");
    }
}