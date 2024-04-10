#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,kmp[1000005],f[1000005];
char a[1000005];
int main(){
    scanf("%s",a+1);
    n=strlen(a+1);
    int j=0;
    for (int i=2;i<=n;i++){
        while(a[j+1]!=a[i]&&(j!=0))j=kmp[j];
        if (a[j+1]==a[i])j++;
        kmp[i]=j;
        f[j]++;
    }
    for (int i=n;i>=1;i--)f[kmp[i]]+=f[i];
    j=kmp[n];
    while(j!=0){
        if (f[j]>=2){
            for (int i=1;i<=j;i++)putchar(a[i]);
            cout<<endl;
            return 0;
        }
        j=kmp[j];
    }
    cout<<"Just a legend"<<endl;
    return 0;
}