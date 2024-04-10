#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=105;

long long d[maxn],h[maxn];

int main(){
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        long long x,mx=0xc000c000c000c000,md=0xc000c000c000c000;
        cin>>n>>x;
        for(int i=1;i<=n;i++){
            cin>>d[i]>>h[i];
            mx=max(mx,d[i]-h[i]);
            md=max(md,d[i]);
        }
        if(md>=x){
            cout<<"1\n";
            continue;
        }
        if(mx<=0){
            cout<<"-1\n";
            continue;
        }
        long long dl=x-md;
        cout<<(dl+mx-1)/mx+1<<'\n';
    }
    return 0;
}