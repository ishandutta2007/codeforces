#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int d[100005],u[100005],v[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n,t,m=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        if(t>m)m=t;
        if(u[t]==0){u[t]=1;v[t]=i;}
        else if(u[t]==-1)continue;
        else if(u[t]==1){d[t]=i-v[t];v[t]=i;u[t]=2;}
        else{
            if(d[t]==(i-v[t]))v[t]=i;
            else u[t]=-1;
        }
    }
    t=0;
    for(int i=1;i<=m;i++){
        if(u[i]>0)t++;
    }
    cout<<t<<"\n";
    for(int i=1;i<=m;i++){
        if(u[i]<1)continue;
        cout<<i<<" "<<d[i]<<"\n";
    }
}