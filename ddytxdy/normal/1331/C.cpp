#include<bits/stdc++.h>
using namespace std;
const int N=3e5+50;
int n,a[7]={0,5,2,4,3,1,6},p[N];char s[100];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=6;i++)p[i]=n>>(i-1)&1;n=0;
    for(int i=1;i<=6;i++)n+=p[a[i]]<<(i-1);
    cout<<n;
    return 0;
}