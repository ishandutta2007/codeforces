#include<bits/stdc++.h>
using namespace std;

int n,k,h[105];

int thrw(){
    int res=1;
    while(h[res]>=h[res+1]&&res<=n)res++;
    if(res<=n)h[res]++;
    else res=-1;
    return res;
}

void mian(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>h[i];
    h[n+1]=0;
    int pos;
    while(k){
        pos=thrw();
        k--;
        if(k==0||pos==-1)break;
    }
    cout<<pos<<'\n';
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