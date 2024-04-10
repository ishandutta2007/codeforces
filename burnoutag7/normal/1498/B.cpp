#include<bits/stdc++.h>
using namespace std;

int n,m,c[32];

void mian(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int w;
        cin>>w;
        for(int j=0;w;j++){
            c[j]+=w&1;
            w>>=1;
        }
    }
    int ans=0;
    while(*max_element(c,c+32)){
        ans++;
        int a=0;
        for(int i=30;i>=0;i--){
            if(m>>i&1)a++;
            if(a>=c[i]){
                a-=c[i];
                c[i]=0;
            }else{
                c[i]-=a;
                a=0;
            }
            a<<=1;
        }
    }
    cout<<ans<<'\n';
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