#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    while(b){
        a=a%b;
        swap(a,b);
    }
    return a;
}

int n,m,a[200005];

void mian(){
    cin>>n;
    m=0;
    int g=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        g=gcd(a[i],g);
    }
    map<int,vector<int>> ps;
    for(int i=1;i<=n;i++){
        a[i]/=g;
        int tmp=a[i];
        for(int j=2;j*j<=tmp;j++){
            if(tmp%j==0){
                while(tmp%j==0)tmp/=j;
                ps[j].emplace_back(i);
            }
        }
        if(tmp>1)ps[tmp].emplace_back(i);
    }
    int ans=0;
    for(auto p:ps){
        int prv=0,len=0;
        for(int x:p.second){
            if(x==prv%n+1)prv++,len++;
            else{
                ans=max(ans,len);
                prv=x;
                len=1;
            }
        }
        for(int x:p.second){
            if(x==prv%n+1)prv++,len++;
            else{
                ans=max(ans,len);
                prv=x;
                len=1;
            }
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