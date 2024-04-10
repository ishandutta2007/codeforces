#include<bits/stdc++.h>
using namespace std;

int n;
int a[200005];
int pos[200005];
int neg[200005];
long long ansp,ansn;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>0){
            pos[i]=pos[i-1]+1;
            neg[i]=neg[i-1];
        }else{
            pos[i]=neg[i-1];
            neg[i]=pos[i-1]+1;
        }
    }
    for(int i=1;i<=n;i++){
        ansp+=pos[i];
        ansn+=neg[i];
    }
    cout<<ansn<<' '<<ansp<<endl;

    return 0;
}