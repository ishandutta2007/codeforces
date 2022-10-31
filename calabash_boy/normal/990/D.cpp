//
// Created by calabash_boy on 18-6-11.
//
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
bool mp[maxn][maxn];
int label[maxn];
int n,a,b;
int main(){
    cin>>n>>a>>b;
    if(min(a,b)!=1||n==2&&a==b||n==3&&a==1&&b==1){
        cout<<"NO"<<endl;
        return 0;
    }
    if(n==1){
        cout<<"YES\n0"<<endl;
        return 0;
    }
    int m = max(a,b);
    for (int i=1;i<=n;i++){
        label[i] = i%m;
    }
    cout<<"YES"<<endl;
    if(a==1&&b==1){
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                if(abs(i-j)==1){
                    mp[i][j]=1;
                }
            }
        }
    }else{
        for (int i=1;i<=n;i++){
            for (int j=1;j<=n;j++){
                mp[i][j] = (label[i]!=label[j])^(m==a);
            }
        }
    }
    for (int i=1;i<=n;i++){
        mp[i][i]=0;
        for (int j=1;j<=n;j++){
            
            if(mp[i][j]){
                printf("1");
            }else{
                printf("0");
            }
        }
        puts("");
    }
    return 0;

}