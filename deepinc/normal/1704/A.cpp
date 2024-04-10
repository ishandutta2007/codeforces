#include<bits/stdc++.h>
using namespace std;
int n,m,t;
char s[1000],d[1000];
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m>>s>>d;
        for(int i=1;i<m;++i) if(s[n-i]!=d[m-i]) goto fail;
        for(int i=0;i<=n-m;++i) if(s[i]==d[0]) goto succ;
        puts("NO"); continue;
        succ: puts("YES"); continue;
        fail: puts("NO");
    }
}