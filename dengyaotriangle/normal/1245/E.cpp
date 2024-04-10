#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=10;
const int maxs=100;

int h[maxn][maxn];
int id[maxn][maxn];
int nxt[maxs];
double ex[maxs+12];

int main(){
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            cin>>h[i][j];
        }
    } 
    int p=0;
    for(int i=0;i<maxn;i++){
        if(i&1){
            for(int j=maxn-1;j>=0;j--){
                id[i][j]=++p;
                if(h[i][j]!=0){
                    nxt[p]=id[i-h[i][j]][j];
                }
            }
        }else{
            for(int j=0;j<maxn;j++){
                id[i][j]=++p;
                if(h[i][j]!=0){
                    nxt[p]=id[i-h[i][j]][j];
                }
            }
        }
    }
    ex[1]=0;
    for(int i=2;i<=100;i++){
        int stp=0;double sum=0;
        for(int j=1;j<=6;j++){
            if(i-j<=0){
                stp++;
            }else{
                if(nxt[i-j])sum+=min(ex[i-j]+1.0,ex[nxt[i-j]]+1.0);
                else sum+=ex[i-j]+1.0;
            }
        }
        ex[i]=(stp+sum)/(6.0-stp);
        cerr<<fixed<<setprecision(15)<<ex[i]<<endl;
    }
    cout<<fixed<<setprecision(15)<<ex[100];
    return 0;
}