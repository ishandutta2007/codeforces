#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,tp;char c[N];bool flag;
int main(){
    scanf("%d%s",&n,c+1);
    for(int i=1;i<=n;i++){
        if(c[i]=='(')tp++;
        else if(tp)tp--;
        else if(flag)puts("NO"),exit(0);
        else flag=1;
    }
    if(!flag&&!tp)puts("YES"),exit(0);
    if(flag&&tp==1)puts("YES"),exit(0);
    puts("NO");
}