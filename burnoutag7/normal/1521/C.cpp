#include<bits/stdc++.h>
using namespace std;

int n,p[10005],p1;

void mian(){
    cin>>n;
    for(int i=1;i<=n;i+=2){
        i-=i==n;
        cout<<"? 2 "<<i<<' '<<i+1<<" 1"<<endl;
        int cur;
        cin>>cur;
        if(cur==1){
            p1=i;
        }else if(cur==2){
            cout<<"? 2 "<<i+1<<' '<<i<<" 1"<<endl;
            cin>>cur;
            if(cur==1)p1=i+1;
        }
    }
    p[p1]=1;
    for(int i=1;i<=n;i++)if(i!=p1){
        cout<<"? 1 "<<p1<<' '<<i<<' '<<n-1<<endl;
        cin>>p[i];
    }
    cout<<"! ";
    for(int i=1;i<=n;i++)cout<<p[i]<<' ';
    cout<<endl;
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