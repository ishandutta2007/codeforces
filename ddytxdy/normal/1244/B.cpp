#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int t,n,mn,mx;char s[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%s",&n,s+1);mn=mx=0;
        for(int i=1;i<=n;i++)if(s[i]=='1'){mx=i;if(!mn)mn=i;}
        if(!mn)printf("%d\n",n);
        else printf("%d\n",2*(n-min(mn-1,n-mx)));
    }
    return 0;
}