#include<bits/stdc++.h>
using namespace std;

int n,q;
int a[405];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>q;
    while(q--){
        cin>>n;
        for(int i=1;i<=4*n;i++){
            cin>>a[i];
        }
        sort(a+1,a+1+(n*4));
        int l=1,r=n*4,area=-1;
        bool f=true;
        while(l+3<=r){
            if(a[l]!=a[l+1]||a[r]!=a[r-1]||(area!=-1&&area!=a[l]*a[r])){
                f=false;
                break;
            }
            area=a[l]*a[r];
            l+=2;
            r-=2;
        }
        if(f){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}