#include<bits/stdc++.h>
using namespace std;

int n,a,b,f[105][105];
char s[105];

void mian(){
    cin>>n>>a>>b;
    cin>>s+1;
    if(b>=0){
        cout<<n*(a+b)<<'\n';
        return;
    }
    int cnt=1;
    for(int i=1;i<n;i++)cnt+=s[i]!=s[i+1];
    cout<<n*a+(cnt/2+1)*b<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}