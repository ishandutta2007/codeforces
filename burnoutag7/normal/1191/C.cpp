#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n,m,k;
ll p[100005];
ll off,pos,itr,cnt;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>p[i];
    }
    p[m+1]=2e18;
    itr=1;
    while(itr<=m){//cout<<"ITR"<<itr<<endl;
        pos=((p[itr]-off+k-1)/k)*k;//cout<<p[itr]<<' ';cout<<"POS"<<pos<<endl;
        int md=itr;
        while(p[md+1]-off<=pos)md++;//cout<<"MD"<<md<<endl;
        off+=md-itr+1;
        cnt++;
        itr=md+1;
    }
    cout<<cnt<<endl;

    return 0;
}