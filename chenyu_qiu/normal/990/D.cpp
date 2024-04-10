#include<bits/stdc++.h>
using namespace std;
bool vis[1000+10][1000+10];
int main() {
    int n,a,b;
    cin>>n>>a>>b;
    if(n==1){
        cout<<"YES"<<endl;
        cout<<0<<endl;
        return 0;
    }
    if((a!=1&&b!=1)||(n<=3&&a==1&&b==1)) {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    int c = n-max(a,b); //c 1 1
    memset(vis,0,sizeof(vis));
    if(a==b){
        for (int i=1;i<c;i++) {
            vis[0][i]=1,vis[i][0]=1;
        }
        vis[1][n-1] = 1;
        vis[n-1][1] = 1;
    } else {
        for (int i=1;i<=c;i++) {
            vis[0][i]=1,vis[i][0]=1;
        }
    }
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a>b) cout<<vis[i][j];
            else {
                if(i==j) {cout<<0;continue;}
                if(vis[i][j]==0) cout<<1;
                else cout<<0;
            }
        }   
        cout<<endl;
    }
    return 0;
}