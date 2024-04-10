#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k,n,m,a[maxn];
int main(){
    int T;
    cin>>T;
    while(T--){
        scanf("%d",&n);
        int r1,c1,r2,c2,r3,c3;
        scanf("%d%d%d%d%d%d",&r1,&c1,&r2,&c2,&r3,&c3);
        int x,y;
        scanf("%d%d",&x,&y);
        int X=(r1*2+r2*2+r3*2+3)/6,Y=(c1*2+c2*2+c3*2+3)/6;
        // cerr<<"X="<<X<<" Y="<<Y<<endl;
        if(X==1 && Y==1){
            if(y==1 || x==1)puts("YES");
            else puts("NO");
        }else
        if(X==1 && Y==n){
            if(y==n || x==1)puts("YES");
            else puts("NO");
        }else
        if(X==n && Y==1){
            if(y==1 || x==n)puts("YES");
            else puts("NO");
        }else
        if(X==n && Y==n){
            if(y==n || x==n)puts("YES");
            else puts("NO");
        }else
        if(r1%2==x%2 && c1%2==y%2)puts("YES");
        else if(r2%2==x%2 && c2%2==y%2)puts("YES");
        else if(r3%2==x%2 && c3%2==y%2)puts("YES");
        else puts("NO");
    }
}