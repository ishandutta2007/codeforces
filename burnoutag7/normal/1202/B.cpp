#include<bits/stdc++.h>
using namespace std;

string s;
int tms[10][10][10];
int ans[10][10];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s;
    memset(tms,-1,sizeof(tms));
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            tms[i][i][j]=0;
            tms[j][i][j]=0;
        }
    }
    for(int _=0;_<=1000;_++){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    if(tms[i][j][k]!=-1){
                        if(tms[(i+j)%10][j][k]==-1||tms[(i+j)%10][j][k]>tms[i][j][k]+1){
                            tms[(i+j)%10][j][k]=tms[i][j][k]+1;
                        }
                        if(tms[(i+k)%10][j][k]==-1||tms[(i+k)%10][j][k]>tms[i][j][k]+1){
                            tms[(i+k)%10][j][k]=tms[i][j][k]+1;
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<s.size();i++){
        int len=(s[i]-s[i-1]+10)%10;
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                if(ans[j][k]==-1)continue;
                if(tms[len][j][k]==-1){
                    ans[j][k]=-1;
                }else{
                    ans[j][k]+=tms[len][j][k];
                }
            }
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}