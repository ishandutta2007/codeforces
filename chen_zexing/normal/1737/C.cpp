#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int check(int x,int y,int n){
    if(x==1&&y==1) return 1;
    if(x==n&&y==1) return 2;
    if(x==1&&y==n) return 3;
    if(x==n&&y==n) return 4;
    return 0;
}
int check2(int x,int y,int n){
    if(x==1&&y==2||x==2&&y==1) return 1;
    if(x==n-1&&y==1||x==n&&y==2) return 2;
    if(x==1&&y==n-1||x==2&&y==n) return 3;
    if(x==n-1&&y==n||x==n&&y==n-1) return 4;
    return -1;
}
int main(){
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        int r1,c1,r2,c2,r3,c3,f[2][2]={},fl=0;
        scanf("%d%d%d%d%d%d",&r1,&c1,&r2,&c2,&r3,&c3);
        int x,y;
        scanf("%d%d",&x,&y);
        f[r1%2][c1%2]=f[r2%2][c2%2]=f[r3%2][c3%2]=1;
        if(check(r1,c1,n)==check2(r2,c2,n)&&check(r1,c1,n)==check2(r3,c3,n)||check(r2,c2,n)==check2(r1,c1,n)&&check(r2,c2,n)==check2(r3,c3,n)||check(r3,c3,n)==check2(r2,c2,n)&&check(r3,c3,n)==check2(r1,c1,n)) fl=1;
        if(fl){
            int temp=check(r1,c1,n)+check(r2,c2,n)+check(r3,c3,n);
            if(temp==1) puts(x==1||y==1?"YES":"NO");
            else if(temp==2) puts(x==n||y==1?"YES":"NO");
            else if(temp==3) puts(x==1||y==n?"YES":"NO");
            else puts(x==n||y==n?"YES":"NO");
            continue;
        }
        puts(f[x%2][y%2]?"YES":"NO");
    }
    return 0;
}