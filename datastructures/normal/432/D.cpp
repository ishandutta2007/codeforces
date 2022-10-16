#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,tot,ans[1000005],sum[1000005],kmp[1000005],f[1000005];
char a[1000005];
int main(){
    scanf("%s",a+1);
    n=strlen(a+1);
    int j=0;
    for (int i=2;i<=n;i++){
        while(j!=0&&a[j+1]!=a[i])j=kmp[j];
        if (a[j+1]==a[i])j++;
        kmp[i]=j;
        f[j]++;
    }
    for (int i=n;i>=1;i--)f[kmp[i]]+=f[i];
    j=kmp[n];
    ans[++tot]=n;
    while(j!=0)ans[++tot]=j,j=kmp[j];
    cout<<tot<<endl;
    for (int i=tot;i>=1;i--)
        printf("%d %d\n",ans[i],f[ans[i]]+1);
}