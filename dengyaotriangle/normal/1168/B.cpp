#include<iostream>
#include<cstring>
using namespace std;

const int maxn=300005;

char s[maxn];
int n;

bool brute(int l,int r){
    for(int i=l;i<=r;i++){
        for(int j=1;j<=(r-l+1);j++){
            if(i-j>=l&&i+j<=r) if(s[i]==s[i-j]&&s[i]==s[i+j]) return 1;
        }
    }
    return 0;
}
int main(){/*
    for(int i=1;i<=20;i++){
        bool ok=1;
        for(int j=0;j<(1<<i);j++){
            bool hs=0;
            for(int a=0;a<i;a++){
                for(int b=1;b<i;b++){
                    if(a-b>=0&&a+b<i)if(((j>>a)&1)==((j>>(a-b))&1)&&((j>>a)&1)==((j>>(a+b))&1)) hs=1;
                }
            }
            if(!hs)ok=0;
        }
        if(ok){
            cout<<i;
            return 0;
        }
    }*/
    ios::sync_with_stdio(0);
    cin>>(s+1);
    n=strlen(s+1);
    long long ans=0;
    for(int i=1;i<=n;i++){
        int lp=n+1;
        for(int j=i;j<=n;j++){
            if(brute(i,j)){
                lp=j;
                break;
            }
        }
        ans+=n-lp+1;
    }
    cout<<ans;
    return 0;
}