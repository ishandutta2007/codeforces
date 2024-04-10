#include<bits/stdc++.h>
#define outY puts("YES")
#define outN puts("NO")
using namespace std;
const int maxn=100010;
int i,j,k,n,m,T,a[maxn];
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        int c0=0,c1=0;
        for(i=1;i<=n;i++){
            int x;scanf("%d",&x);
            if(x%2)c1++;else c0++;
        }
        if((c1%2==0) && (c0%2==1) && (c1%4==0))puts("Alice");
        else if((c1%2==0) && (c0%2==1) && (c1%4==2))puts("Bob");
        else if((c1%2==0) && (c0%2==0) && (c1%4==2))puts("Bob");
        else if((c1%2==0) && (c0%2==0) && (c1%4==0))puts("Alice");
        else if((c1%2==1) && (c0%2==1))puts("Alice");
        else if((c1%2==1) && (c0%2==0) && (c1-1)%4==2)puts("Alice");
        else if((c1%2==1) && (c0%2==0) && (c1-1)%4==0)puts("Bob");
    }
}
/*
1 1 1 1 1 0 0 0

1 1 1 0 0 0 0 0

1 1 1 1 1 1 0 0

1 1 1 1 0 0
*/