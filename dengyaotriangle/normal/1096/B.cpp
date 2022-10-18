#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;
const long long mdn=998244353;

int n;
char x[maxn];

int main(){
    cin>>n;
    cin>>(x+1);
    long long lm=1,rm=1;
    for(int i=2;i<=n;i++){
        if(x[i]==x[i-1])lm++;
        else break;
    }
    for(int i=n-1;i>=1;i--){
        if(x[i]==x[i+1])rm++;
        else break;
    }
    if(x[1]==x[n]){
        cout<<((lm+1)*(rm+1))%mdn;
    }else{
        cout<<(lm+rm+1)%mdn;
    }
    return 0;
}