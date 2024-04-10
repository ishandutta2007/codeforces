#include<bits/stdc++.h>
using namespace std;

int g[4][4];
double mat[6][8]={
    {0,0,0,1,1,1,1,0},
    {0,1,1,0,0,1,1,0},
    {1,0,1,0,1,0,1,0},
    {0,1,1,1,1,0,0,0},
    {1,0,1,1,0,1,0,0},
    {1,1,0,0,1,1,0,0}
},eps=1e-10,x[7],anss=1e9;
int ans[7],tmp[7];
string s[4];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<6;i++)cin>>mat[i][7];
    int r=0,c=0;
    for(;r<6&&c<7;r++,c++){
        {
            int p=r;
            for(int i=r;i<6;i++)if(abs(mat[i][c])>abs(mat[p][c]))p=i;
            swap(mat[p],mat[r]);
        }
        if(abs(mat[r][c])<eps){
            r--;
            continue;
        }
        for(int i=c+1;i<8;i++)mat[r][i]/=mat[r][c];
        mat[r][c]=1;
        for(int i=r+1;i<6;i++){
            for(int j=c+1;j<8;j++)mat[i][j]-=mat[i][c]*mat[r][j];
            mat[i][c]=0;
        }
    }
    for(int i=0;i<6;i++){
        bool f=false;
        for(int j=0;j<7;j++){
            f|=abs(mat[i][j])>=eps;
        }
        if(!f&&abs(mat[i][7])>=eps){
            cout<<"-1\n";
            return 0;
        }
    }
    for(double &xn=x[6]=0;xn<=114514;xn+=1){
        double sum=xn;
        bool f=true;
        for(int i=5;i>=0;i--){
            x[i]=mat[i][7];
            for(int j=6;j>i;j--)x[i]-=mat[i][j]*x[j];
            sum+=x[i];
            f&=x[i]>-eps;
        }
        for(int i=0;i<7;i++)tmp[i]=x[i]+0.5,f&=tmp[i]+eps>=x[i]&&tmp[i]-eps<=x[i];
        if(f&&sum+eps<=anss){
            anss=sum;
            for(int i=0;i<7;i++)ans[i]=tmp[i];
        }
    }
    if(anss==1e9){
        cout<<"-1\n";
        return 0;
    }
    cout<<int(anss+0.5)<<endl;
    for(int i=0;i<7;i++){
        while(ans[i]--){
            for(int j=0;j<4;j++)s[j]+=(i+1>>3-j&1)+'a';
        }
    }
    for(int i=0;i<4;i++)cout<<s[i]<<endl;

    return 0;
}