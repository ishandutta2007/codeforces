#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=100005;

char s[maxn],t[maxn];
int n,m;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int ts;
    cin>>ts;
    while(ts--){
        cin>>(s+1)>>(t+1);
        n=strlen(s+1);m=strlen(t+1);
        bool ok=1;
        int p=1+((n-m)&1);
        for(int i=1;i<=m;i++){
            while(p<=n&&t[i]!=s[p])p+=2;
            if(p>n){
                ok=0;
                break;
            }
            p++;
        }
        cout<<(ok?"YES\n":"NO\n");
    }
    return 0;
}