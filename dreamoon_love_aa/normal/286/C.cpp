#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
int p[1000001],st[1000001],sn;
void neg(int& x){
    if(x>0)x=-x;
}
int main(){
    int i,j,k,n,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&p[i]);
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        int x;
        scanf("%d",&x);
        p[x]=-p[x];
    }
    reverse(p+1,p+n+1);
    sn=0;
    for(i=1;i<=n;i++){
        st[sn++]=i;
        if(sn>=2&&abs(p[st[sn-1]])==abs(p[st[sn-2]])){
            if(p[st[sn-1]]>0){
                neg(p[st[sn-2]]);
                sn-=2;
            }
        }
    }
    if(sn==0){
        puts("YES");
        reverse(p+1,p+1+n);
        for(i=1;i<=n;i++){
            if(i!=1)printf(" ");
            printf("%d",p[i]);
        }
        puts("");
    }
    else puts("NO");
    return 0;
}