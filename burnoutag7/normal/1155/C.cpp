#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int m;
ll x[300005];
ll p[300005];
ll g;
ll y,j;

ll GCD(ll a,ll b){
    if(b==0)return a;
    return GCD(b,a%b);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=0;i<m;i++){
        cin>>p[i];
    }
    g=x[1]-x[0];
    for(int i=1;i<n-1;i++){
        g=GCD(g,x[i+1]-x[i]);
    }
    j=-1;
    for(int i=0;i<m;i++){
        if(g%p[i]==0){
            j=i;
            break;
        }
    }
    y=x[0];
    if(j==-1){
        cout<<"NO"<<endl;
        return 0;
    }else{
        cout<<"YES"<<endl;
    }
    cout<<y<<' '<<j+1<<endl;

    return 0;
}