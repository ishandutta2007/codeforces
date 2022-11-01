#include<bits/stdc++.h>
using namespace std;

int n,d;
bool a[1000005],vis[1000005];

void mian(){
    cin>>n>>d;
    memset(vis,0,n);
    for(int i=0;i<n;i++){
        char c;
        cin>>c;
        a[i]=c-'0';
    }
    int mx=0,vc=0;
    for(int i=0;i<n;i++)if(!vis[i]&&!a[i]){
        vis[i]=1;
        vc++;
        int c=0;
        for(int x=(i+d)%n;x!=i;x=(x+d)%n){
            vis[x]=1;
            vc++;
            if(a[x])c++;
            else{
                mx=max(mx,c);
                c=0;
            }
        }
        mx=max(mx,c);
    }
    cout<<(vc==n?mx:-1)<<'\n';
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