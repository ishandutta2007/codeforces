#include<bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int pos;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    a[0]=1e9;
    for(int i=1;i<=n;i++){
        if(a[i]>=0)a[i]=-a[i]-1;
        if(a[i]<a[pos]&&a[i]!=-1)pos=i;
    }
    if(n%2){
        if(pos!=0)a[pos]=-a[pos]-1;
        else{
            for(int i=1;i<=n;i++){
                if(a[i]==-1){
                    a[i]=0;
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;

    return 0;
}