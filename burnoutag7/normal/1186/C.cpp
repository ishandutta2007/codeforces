#include<bits/stdc++.h>
using namespace std;
//Echo Act 3
string a,b;
int ca,cb,cnt;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>a>>b;
    for(int i=0;i<b.size();i++){
        cb+=b[i]=='1';
        ca+=a[i]=='1';
    }
    cnt+=((ca+cb)&1)==0;
    for(int i=b.size();i<a.size();i++){
        ca+=a[i]=='1';
        ca-=a[i-b.size()]=='1';
        cnt+=((ca+cb)&1)==0;
    }
    cout<<cnt<<endl;

    return 0;
}