#include<bits/stdc++.h>
using namespace std;

int n;
bool pd[1020];
bool u[1005];

int lft(int x){
    for(int i=x;i<=1010;i++){
        if(!pd[i])return i;
    }
    return 0;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pd[1]=1;
    for(int i=1;i<=1010;i++){
        if(pd[i])continue;
        for(int j=i+i;j<=1010;j+=i){
            pd[j]=1;
        }
    }
    cin>>n;
    cout<<lft(n)<<endl;
    int l=lft(n)-n;
    for(int i=1;i<=n;i++){
        cout<<i<<' '<<(i==n?i+1-n:i+1)<<endl;
    }
    for(int i=1;l>0;i++){
        if(u[i]||u[(i>=n-1?i+2-n:i+2)])continue;
        u[i]=1;
        u[(i>=n-1?i+2-n:i+2)]=1;
        l--;
        cout<<i<<' '<<(i>=n-1?i+2-n:i+2)<<endl;
    }

    return 0;
}