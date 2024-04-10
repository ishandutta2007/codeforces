#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

int n;
long long k;
char x[maxn];
long long ed[maxn][maxn];
long long en[maxn];
bool apr[maxn];

int main(){
    cin>>n>>k;
    cin>>(x+1);
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(i==1){
            memset(apr,0,sizeof(apr));
            for(int j=1;j<=n;j++){
                if(!apr[x[j]-'a']){
                    apr[x[j]-'a']=1;
                    ed[1][j]=1;
                }
            }
        }else{
            for(int j=1;j<=n;j++){
                memset(apr,0,sizeof(apr));
                for(int k=j+1;k<=n;k++){
                    if(!apr[x[k]-'a']){
                        apr[x[k]-'a']=1;
                        ed[i][k]+=ed[i-1][j];
                    }
                }
            }
        }
    }
    for(int i=n;i>=0;i--){
        long long cc=n-i,sz=0;
        for(int j=1;j<=n;j++){
            sz+=ed[i][j];
        }
        if(i==0) sz=1;
        if(sz>=k){
            ans+=cc*k;
            cout<<ans;
            return 0;
        }
        ans+=cc*sz;
        k-=sz;
    }
    cout<<-1;
    return 0;
}