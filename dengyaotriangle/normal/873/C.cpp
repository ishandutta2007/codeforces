#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

int n,m,k1;
int a[maxn][maxn];

int main(){
    cin>>n>>m>>k1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    int a1=0,a2=0;
    for(int i=1;i<=m;i++){
        int cnt=0,cm=0,cc=0;
        for(int j=1;j<=n;j++){
            if(a[j][i]==1){
                int c0=0;
                for(int k=j;k<=min(j+k1-1,n);k++){
                    if(a[k][i]) c0++;
                }
                if(c0>cm){
                    cm=c0;
                    cc=cnt;
                }
                cnt++;
            }
        }
        a1+=cm,a2+=cc;
    }
    cout<<a1<<' '<<a2;
    return 0;
}