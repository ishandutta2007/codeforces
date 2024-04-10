#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;
const int maxl=20;

int n;
int a[maxn];
int nxt[maxn][maxl];
int ls[maxl];

int main(){
    ios::sync_with_stdio(0);
    int q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    memset(ls,-1,sizeof(ls));
    memset(nxt,0x3f,sizeof(nxt));
    for(int i=n;i>=1;i--){
        for(int j=0;j<maxl;j++){
            if((a[i]>>j)&1){
                nxt[i][j]=i;
                if(ls[j]!=-1){
                    for(int k=0;k<maxl;k++){
                        nxt[i][k]=min(nxt[i][k],nxt[ls[j]][k]);
                    }
                }  
                ls[j]=i;
            }
        }
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        bool ans=0;
        for(int i=0;i<maxl;i++){
            if((a[r]>>i)&1)ans|=(nxt[l][i]<=r);
        }
        cout<<(ans?"Shi\n":"Fou\n");
    }
    return 0;
}