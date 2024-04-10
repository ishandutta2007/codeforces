#include<bits/stdc++.h>
 
using namespace std;
 
const int maxn=5005;
 
int l[maxn],r[maxn];
int n,q;
int cf[maxn],pfx[maxn];
 
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>q;
    for(int i=1;i<=q;i++)cin>>l[i]>>r[i];
    int ans=0;
    for(int i=1;i<=q;i++){
        memset(cf,0,sizeof(cf));
        for(int j=1;j<=q;j++){
            if(j!=i){
                cf[l[j]]++;cf[r[j]+1]--;
            }
        }
        int cur=0;
        for(int j=1;j<=n;j++){
            cf[j]+=cf[j-1];
            if(cf[j]>0) cur++;
        }
        for(int j=1;j<=n;j++){
            pfx[j]=pfx[j-1]+(int)(cf[j]==1);
        }
        for(int j=1;j<=q;j++){
            if(i!=j){
                ans=max(ans,cur-pfx[r[j]]+pfx[l[j]-1]);
            }
        }
    }
    cout<<ans;
    return 0;
}//lmyakioi123