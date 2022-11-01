#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,prv[30];
ll k;
__int128_t f[105][105];
char s[105];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k>>s+1;
    for(int i=1;i<=n;i++){
        if(prv[s[i]-'a']){
            f[i][1]=f[i-1][1];
            for(int j=2;j<=i;j++){
                f[i][j]=f[i-1][j-1]-f[prv[s[i]-'a']-1][j-1]+f[i-1][j];
            }
        }else{
            f[i][1]=1+f[i-1][1];
            for(int j=2;j<=i;j++){
                f[i][j]=f[i-1][j-1]+f[i-1][j];
            }
        }
        prv[s[i]-'a']=i;
    }
    f[n][0]=1;
    ll c=0;
    for(int i=n;i>=0;i--){
        if(f[n][i]>=k){
            c+=k*(n-i);
            k=0;
            break;
        }else{
            k-=f[n][i];
            c+=f[n][i]*(n-i);
        }
    }
    cout<<(k?-1:c);

    return 0;
}