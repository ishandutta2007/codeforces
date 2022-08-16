#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    ios_base::sync_with_stdio(false);
    int m,n,c=0;
    cin>>m>>n;
    int t[m][n];
    for(int i=0;i<m;i++)for(int j=0;j<n;j++)cin>>t[i][j];
    int a[]={0,0,0,0,0};
    int w[]={1,0,0,0,0};
    int e[]={0,0,0,0,0};
    e[0]=t[0][0];
    while(a[n-1]<m){
        int r=-1;
        for(int i=0;i<n;i++){
            if(w[i]==0&&(i==0||a[i-1]>a[i])){w[i]=1;e[i]=c+t[a[i]][i];}
            if(w[i]==0)continue;
            if(e[i]<r||r==-1)r=e[i];
        }
        c=r;
        for(int i=0;i<n;i++){
            if(w[i]==0)continue;
            if(e[i]==c){
                w[i]=0;a[i]++;
                if(i==n-1){cout<<c<<" ";}
            }
        }
    }
}