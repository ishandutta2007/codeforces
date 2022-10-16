#include <iostream>
#include <cstdio>
using namespace std;
int n,m,x[1000005];
int a[1000005],b[1000005],kmp[1000005],ans;
int main(){
    cin>>n>>m;
    n--,m--;
    for (int i=0;i<=n;i++){
        scanf("%d",&x[i]);
        if (i>0)a[i]=x[i]-x[i-1];
    }
    for (int i=0;i<=m;i++){
        scanf("%d",&x[i]);
        if (i>0)b[i]=x[i]-x[i-1];
    }
    if (m==0){
        cout<<n+1<<endl;
        return 0;
    }
    int j=0;
    for (int i=2;i<=m;i++){
        while(j&&b[j+1]!=b[i])j=kmp[j];
        if (b[j+1]==b[i])j++;
        kmp[i]=j;
    }
    j=0;
    for (int i=1;i<=n;i++){
        while(j&&b[j+1]!=a[i])j=kmp[j];
        if (b[j+1]==a[i])j++;
        if (j==m){
            ans++;
            j=kmp[j];
        }
    }
    cout<<ans<<endl;
    return 0;
}