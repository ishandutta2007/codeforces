#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k,n,m;
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        int w=0;
        for(i=1;i<=n;i++)scanf("%d",&k),w=max(w,k);
        if(w==1)puts("YES");else puts("NO");
    }
}