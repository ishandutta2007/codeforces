#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[1234],q[1234],ind[1234];
char s[533333];
int f[]={8, 1, 1, 2, 0, 3, 1, 1, 0, 3, 3, 2, 2, 4, 4, 5, 5, 9, 3, 3, 0, 1, 1, 3, 0, 2, 1, 1, 0, 4, 5, 3, 7, 4};
int get(int x){
    switch(x){
        case  0:return 0;
        case 14:return 0;
        case 16:return 2;
        case 17:return 2;
        case 31:return 2;
        case 34:return 0;
        case 51:return 2;
        default:return f[x%34];
    }
}
int main(){
    cin>>t;
    while(t--){
        cin>>n>>s;
        int ans=0;
        for(int i=0;i<n;++i) ans+=s[i]=='R'?1:-1;
        s[n]=s[n-1];
        if(ans>0)puts("Alice");
        else if(ans<0)puts("Bob");
        else{
            for(int i=1,c=0;i<=n;++i) if(s[i]!=s[i-1]) c++; else ans^=get(c),c=0;
            puts(ans?"Alice":"Bob");
        }
    }
}