#include<bits/stdc++.h>
using namespace std;
int n,pos,l,r;
int main(){
    cin>>n>>pos>>l>>r;
    if (l==1&&r==n){
        cout<<0<<endl;
        return 0;
    }
    if (l==1){
        cout<<1+abs(r-pos)<<endl;
        return 0;
    }
    if (r==n){
        cout<<1+abs(pos-l)<<endl;
        return 0;
    }
    if (pos>=l&&pos<=r){
        cout<<2+r-l+min(abs(r-pos),abs(l-pos))<<endl;
        return 0;
    }
    if (pos<l){
        cout<<2+r-pos<<endl;
        return 0;
    }else{
        cout<<2+pos-l<<endl;
        return 0;
    }
    return 0;
}