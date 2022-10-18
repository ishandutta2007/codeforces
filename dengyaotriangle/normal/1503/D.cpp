#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=400005;

int n;
int a[maxn],b[maxn];
int ri[maxn];
int inv[maxn];
bool vis[maxn],pri[maxn];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        ri[a[i]]=ri[b[i]]=i;
        pri[a[i]]=1;
        inv[a[i]]=b[i];
        inv[b[i]]=a[i];
    }
    int cl=1,cr=2*n;
    int ans=0;
    while(cl<=cr){
        if(ri[cl]==ri[cr]){
            cl++;cr--;continue;
        }
        int l0=cl,r0=cr;
        int l1=inv[cr],r1=inv[cl];
        vis[l0]=vis[l1]=vis[r0]=vis[r1]=1;
        int v=pri[cl]+pri[cr],tot=2;
        while(l0<=r0&&(l0<l1||r0>r1)){
            if(l0<l1){
                ++l0;
                if(!vis[l0]){
                    if(inv[l0]>r1){
                        cout<< -1;return 0;
                    }
                    v+=pri[l0];tot++;
                    vis[l0]=1;r1=inv[l0];vis[r1]=1;
                }
            }else if(r0>r1){
                --r0;
                if(!vis[r0]){
                    if(inv[r0]<l1){
                        cout<< -1;return 0;
                    }
                    v+=pri[r0];tot++;
                    vis[r0]=1;l1=inv[r0];vis[l1]=1;
                }
            }
        }
        if(r1<l1){
            cout<< -1;return 0;
        }
        ans+=min(v,tot-v);
        cl=l0+1;cr=r0-1;
    }
    cout<<ans;
    return 0;
}