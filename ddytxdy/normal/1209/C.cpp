#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int t,n,a[N],b[N],col[N];bool flag;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);flag=1;
        for(int i=1;i<=n;i++)scanf("%1d",&a[i]),b[i]=a[i];
        sort(b+1,b+n+1);
        for(int i=1,j=1;i<=n;i++){
            if(a[i]==b[j])col[i]=1,j++;
            else col[i]=2;
        }
        for(int i=1,f1=0,f2=0;i<=n;i++){
            if(col[i]==1){
                if(a[i]<f1)flag=0;
                else f1=a[i];
            }
            else{
                if(a[i]<f2)flag=0;
                else f2=a[i];
            }
        }
        if(!flag)putchar('-');
        else for(int i=1;i<=n;i++)putchar(col[i]+'0');
        puts("");
    }
    return 0;
}