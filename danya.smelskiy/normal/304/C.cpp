#include <bits/stdc++.h>
using namespace std;
int n;

int a[100005];
int b[100005];
int c[100005];
bool used[100005];

int main(){
    cin>>n;
    for (int i=0;i<n;++i)
        a[i]=i;
    b[0]=n-1;
    for (int i=1;i<n;++i)
        b[i]=i-1;
    for (int i=0;i<n;++i){
        c[i]=(a[i]+b[i])%n;
        if (used[c[i]]) {
            cout<<"-1";
            return 0;
        }
        used[c[i]]=true;
    }
    for (int i=0;i<n;++i)
        cout<<a[i]<<" ";
    cout<<'\n';
    for (int i=0;i<n;++i)
        cout<<b[i]<<" ";
    cout<<'\n';
    for (int i=0;i<n;++i)
        cout<<c[i]<<" ";
}