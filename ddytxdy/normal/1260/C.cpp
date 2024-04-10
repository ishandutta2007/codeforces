#include<bits/stdc++.h>
using namespace std;
int n,x,y,z;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&x,&y,&z);if(x>y)swap(x,y);
        int g=gcd(x,y);x/=g;y/=g;
        int d=y/x;
        puts(d+1<z||d+1==z&&y%x==1||x==1&&y-1<z?"OBEY":"REBEL");
    }
    return 0;
}