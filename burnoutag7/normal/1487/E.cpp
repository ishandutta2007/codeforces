#include<bits/stdc++.h>
using namespace std;

int n[4],m[3],a[4][150005],f[4][150005],v[150005],st;
set<int> b[3][150005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n[0]>>n[1]>>n[2]>>n[3];
    for(int i=0;i<4;i++)for(int j=0;j<n[i];j++)cin>>a[i][j];
    for(int i=0;i<3;i++){
        cin>>m[i];
        for(int j=0;j<m[i];j++){
            int x,y;
            cin>>x>>y;
            x--;
            y--;
            b[i][y].insert(x);
        }
    }
    for(int i=0;i<n[0];i++)f[0][i]=a[0][i];
    for(int i=1;i<4;i++){
        iota(v,v+n[i-1],0);
        st=i;
        sort(v,v+n[i-1],[](int a,int b){
            return f[st-1][a]<f[st-1][b];
        });
        for(int j=0;j<n[i];j++){
            int p=0;
            while(p<n[i-1]&&b[i-1][j].find(v[p])!=b[i-1][j].end())p++;
            if(p==n[i-1]||f[i-1][v[p]]==0x3f3f3f3f)f[i][j]=0x3f3f3f3f;
            else f[i][j]=f[i-1][v[p]]+a[i][j];
        }
    }
    int ans=*min_element(f[3],f[3]+n[3]);
    if(ans==0x3f3f3f3f)ans=-1;
    cout<<ans;

    return 0;
}