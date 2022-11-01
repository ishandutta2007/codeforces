#include<bits/stdc++.h>
using namespace std;

int n,f[2][105];
char s[2][105];

void mian(){
    cin>>n>>s[0]>>s[1];
    memset(f,0,sizeof(f));
    f[0][0]=1;
    f[1][0]=s[1][0]=='0';
    for(int i=1;i<n;i++){
        f[0][i]=s[0][i]=='0'&&(f[0][i-1]||f[1][i-1]);
        f[1][i]=s[1][i]=='0'&&(f[0][i-1]||f[1][i-1]);
    }
    cout<<(f[1][n-1]?"YES\n":"NO\n");
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