#include<bits/stdc++.h>
using namespace std;

int p[100005];

void mian(){
    int n,a,b;
    cin>>n>>a>>b;
    iota(p+1,p+1+n,1);
    int i=2;
    while(i+1<n&&a&&b){
        swap(p[i],p[i+1]);
        i+=2;
        a--;
        b--;
    }
    if(a||b){
        if(i==n){
            cout<<"-1\n";
            return;
        }
        reverse(p+i,p+n+1);
        if(a)a--;
        else{
            b--;
            for(int i=1;i<=n;i++)p[i]=n+1-p[i];
        }
    }
    if(a||b){
        cout<<"-1\n";
    }else{
        for(int i=1;i<=n;i++)cout<<p[i]<<' ';
        cout<<'\n';
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}