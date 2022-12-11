#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e5+50;
int T,n;LL l,r;
void solve(){
    scanf("%d%lld%lld",&n,&l,&r);
    for(int i=1;i<n;i++){
        if(l>(n-i)*2)l-=(n-i)*2,r-=(n-i)*2;
        else {
            for(int j=i+1;j<=n;j++){
                if(l>1)l--,r--;
                else printf("%d ",i),r--;
                if(!r)return;
                if(l>1)l--,r--;
                else printf("%d ",j),r--;
                if(!r)return;
            }
        }
    }
    cout<<1;
}
int main(){
    scanf("%d",&T);
    while(T--)solve(),puts("");
    return 0;
}