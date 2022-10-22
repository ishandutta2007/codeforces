#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int i,j,k,n,m,a[maxn],num[maxn];
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;char c;
        for(i=1;i<=26;i++)num[i]=0;
        for(i=1;i<=n;i++)cin>>c,num[c-'a'+1]++;
        for(i=1;i<=m;i++){
            int b=0;
            for(j=1;j<=min(26,n/m);j++){
                // cerr<<"j="<<j<<" "<<num[j]<<endl;
                if(!num[j]){putchar('a'+j-1);b=1;break;}
                num[j]--;
            }
            if(!b)putchar('a'+n/m);
        }puts("");
    }
}