#include<bits/stdc++.h>
using namespace std;
int main(){
    int d,h;
    cin>>d>>h;
    int a[d],b[d],c[d],s=0,us=0;
    for(int i=0;i<d;i++){
        cin>>a[i]>>b[i];
        c[i]=a[i];
        s+=a[i];
        us+=b[i];
    }
    if(s>h||us<h){cout<<"NO";return 0;}
    cout<<"YES"<<endl;
    for(int i=0;i<d;i++){
        s+=b[i]-a[i];
        if(s>=h){
            c[i]=b[i]-(s-h);
            break;
        }
        c[i]=b[i];
    }
    for(int i=0;i<d;i++)
        cout<<c[i]<<" ";
}