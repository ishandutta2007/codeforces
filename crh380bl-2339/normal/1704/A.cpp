#include<bits/stdc++.h>
using namespace std;
char s1[55],s2[55];
void work(){
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s%s",s1+1,s2+1);
    int i,j;
    for(i=n,j=m;j>=2;--j,--i){
        if(i<1||s1[i]!=s2[j]){
            puts("NO");
            return;
        }
    }
    for(;i>=1;--i){
        if(s1[i]==s2[1]){
            puts("YES");
            return;
        }
    }
    puts("NO");
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}