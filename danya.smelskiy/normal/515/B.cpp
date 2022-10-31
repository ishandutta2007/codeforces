#include <bits/stdc++.h>
using namespace std;
int n,m,nn,x,mm,y;
bool used1[105];
bool used2[105];
int main(){
    cin>>n>>m;
    cin>>nn;
    for (int i=1;i<=nn;++i){
        cin>>x;
        used1[x]=true;
    }
    cin>>mm;
    for (int i=1;i<=mm;++i){
        cin>>x;
        used2[x]=true;
    }
    long long z=(n*m)/__gcd(n,m);
    for (int i=0;i<=z*2;++i){
        x=i%n;
        y=i%m;
        if (used1[x]==true) used2[y]=true;
        else if (used2[y]==true) used1[x]=true;
    }
    for (int i=0;i<n;++i)
    if (used1[i]==false){
        cout<<"No";
        return 0;
    }
    for (int i=0;i<m;++i){
        if (used2[i]==false){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}