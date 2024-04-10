#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

char a[maxn],b[maxn];
int c[maxn],d[maxn];
int n;

int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    cin>>(a+1)>>(b+1);
    int jw=0;
    for(int i=n;i>=0;i--){
        int c0=a[i]-'a'+b[i]-'a'+jw;
        if(i==0) c0=jw;
        jw=c0/26;
        c0%=26;
        c[i]=c0;
    }
    int cur=0;
    for(int i=0;i<=n;i++){
        cur*=26;
        cur+=c[i];
        d[i]=cur/2;
        cur%=2;
    }
    for(int i=1;i<=n;i++){
        cout<<(char)(d[i]+'a');
    }
    return 0;
}