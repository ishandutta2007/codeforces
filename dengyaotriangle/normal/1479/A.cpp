#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!
map<int,int> mp;
int n;

int qry(int x){
    if(x<1||x>n)return 1e9;
    if(mp.count(x))return mp[x];
    else{
        cout<<"? "<<x<<endl;
        int k;cin>>k;
        return mp[x]=k;
    }
}
int main(){
    cin>>n;
    int l=1,r=n;
    while(l!=r){
        int m=(l+r)/2;
        if(qry(m)<qry(m+1))r=m;
        else l=m+1;
    }
    cout<<"! "<<l;
    return 0;
}