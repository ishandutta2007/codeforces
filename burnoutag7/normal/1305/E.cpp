#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
int pre[5005];

void solve(int x){
    for(int i=1;i<=x;i++)cout<<i<<' ';
    cout<<2*(x-m+pre[x])+1<<' ';
    for(int i=x+2;i<=n;i++)cout<<1+10000*i+(int)1e8<<' ';
    cout<<endl;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<n;i++){
        pre[i+1]=pre[i]+(i>>1);
        if(pre[i]<=m&&m<pre[i+1]){
            solve(i);
            return 0;
        }
    }
    if(pre[n]==m){
        for(int i=1;i<=n;i++)cout<<i<<' ';
        cout<<endl;
    }else cout<<-1<<endl;

    return 0;
}