#include<bits/stdc++.h>
using namespace std;

int n;
int cur;
int g[1005][1005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i+=4){
        for(int j=0;j<n;j+=4){
            for(int k=0;k<4;k++){
                for(int l=0;l<4;l++){
                    g[i+k][j+l]=cur++;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<g[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}