#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+50;
int n,len;char c[N],b[N];
int main(){
    scanf("%d%s",&n,c+1);
    for(int i=1;i<=n;i++){
        if(len%2==0||b[len]!=c[i])b[++len]=c[i];
    }
    if(len&1)len--;
    printf("%d\n",n-len);
    for(int i=1;i<=len;i++)putchar(b[i]);
    return 0;
}