#include <iostream>
#include <cstdio>
using namespace std;
char a[2000005];
int n,k,kmp[2000005],z[2000005];
int ch[2000005];
inline void GetKMP(){
    int j=0;
    for (int i=2;i<=n;i++){
        while(j&&a[j+1]!=a[i])j=kmp[j];
        if (a[j+1]==a[i])j++;
        kmp[i]=j;
    }
    return;
}
inline void GetZ(){
    int l=0,r=0;
    z[1]=n;
    for (int i=2;i<=n;i++){
        if (i<=r)z[i]=min(z[i-l+1],r-i+1);
        while(i+z[i]<=n&&a[i+z[i]]==a[z[i]+1])z[i]++;
        if (i+z[i]-1>r)l=i,r=i+z[i]-1;
    }
    return;
}
int main(){
    cin>>n>>k;
    scanf("%s",a+1);
    GetKMP();
    GetZ();
    for (int i=1;i<=n;i++){
        if (i%k!=0)continue;
        int len=i/k;
        if (len%(i-kmp[i])!=0)continue;
        ch[i]++,ch[min(i+1+z[i+1],i+1+len)]--;
    }
    for (int i=1;i<=n;i++){
        ch[i]+=ch[i-1];
        if (ch[i]!=0)putchar('1');
        else putchar('0');
    }
    cout<<endl;
    return 0;
}