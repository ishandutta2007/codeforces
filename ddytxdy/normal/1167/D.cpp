#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5+50;
int n,de,now,goal,a[N];char c[N];
int main(){
    scanf("%d%s",&n,c+1);
    for(int i=1;i<=n;i++){
        if(c[i]=='(')now++;
        else now--;
        de=max(de,now);
    }
    goal=de>>1;
    for(int i=1;i<=n;i++){
        if(c[i]=='('){
            now++;
            if(now>goal)a[i]=1;
        }
        else{
            if(now>goal)a[i]=1;
            now--;
        }
    }
    for(int i=1;i<=n;i++)printf("%d",a[i]);
    return 0;
}