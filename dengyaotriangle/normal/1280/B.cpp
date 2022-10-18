#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=66;

char c[maxn][maxn];
int n,m;

int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        bool t=1;
        for(int i=1;i<=n;i++){
            cin>>(c[i]+1);
        }
        bool c0=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(c[i][j]=='A')t=0;
                if(c[i][j]!='A'){c0=0;}
            }
        }
        if(t){cout<<"MORTAL\n";continue;}
        if(c0){cout<<0<<'\n';continue;}
        bool c11=1,c12=1,c13=1,c14=1;
        for(int i=1;i<=m;i++){
            if(c[1][i]!='A')c11=0;
            if(c[n][i]!='A')c12=0;
        }
        for(int i=1;i<=n;i++){
            if(c[i][1]!='A')c13=0;
            if(c[i][m]!='A')c14=0;
        }
        if(c11||c12||c13||c14){cout<<1<<'\n';continue;}
        bool c2=0;
        for(int i=1;i<=n;i++){
            bool f2=1;
            for(int j=1;j<=m;j++){if(c[i][j]!='A')f2=0;}
            if(f2)c2=1;
        }
        for(int i=1;i<=m;i++){
            bool f2=1;
            for(int j=1;j<=n;j++){if(c[j][i]!='A')f2=0;}
            if(f2)c2=1;
        }
        int ub1=0,lb1=n+1,ub2=0,lb2=n+1;
        for(int i=1;i<=n;i++){
            if(c[i][1]!='A')break;
            ub1=i;
        }for(int i=1;i<=n;i++){
            if(c[i][m]!='A')break;
            ub2=i;
        }for(int i=n;i>=1;i--){
            if(c[i][1]!='A')break;
            lb1=i;
        }for(int i=n;i>=1;i--){
            if(c[i][m]!='A')break;
            lb2=i;
        }
        if(ub1+1>=lb2||ub2+1>=lb1)c2=1;
        ub1=0,lb1=m+1,ub2=0,lb2=m+1;
        for(int i=1;i<=m;i++){
            if(c[1][i]!='A')break;
            ub1=i;
        }for(int i=1;i<=m;i++){
            if(c[n][i]!='A')break;
            ub2=i;
        }for(int i=m;i>=1;i--){
            if(c[1][i]!='A')break;
            lb1=i;
        }for(int i=m;i>=1;i--){
            if(c[n][i]!='A')break;
            lb2=i;
        }
        if(ub1+1>=lb2||ub2+1>=lb1)c2=1;
        if(c2||c[1][1]=='A'||c[1][m]=='A'||c[n][1]=='A'||c[n][m]=='A'){cout<<2<<'\n';continue;}
        bool c3=0;
        for(int i=1;i<=m;i++){
            if(c[1][i]=='A')c3=1;
            if(c[n][i]=='A')c3=1;
        }
        for(int i=1;i<=n;i++){
            if(c[i][1]=='A')c3=1;
            if(c[i][m]=='A')c3=1;
        }
        if(c3)cout<<3<<'\n';
        else cout<<4<<'\n';
    }    
    return 0;
}