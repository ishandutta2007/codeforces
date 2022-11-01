#include<bits/stdc++.h>
using namespace std;

int n,a[200005];

bool messup(){
    int l=1,r=n;
    while(a[l]==l)l++;
    while(a[r]==r)r--;
    for(int i=l;i<=r;i++)if(a[i]==i)return 0;
    return 1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(is_sorted(a+1,a+1+n)){
            cout<<"0\n";
        }else if(messup()){
            cout<<"1\n";
        }else cout<<"2\n";
    }

    return 0;
}