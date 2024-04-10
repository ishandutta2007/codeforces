#include<bits/stdc++.h>
char c[1000005];
using namespace std;
int main(){
    int n,a,b,l=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        if(l+a<=500){
            c[i]='A';
            l+=a;
        }
        else{
            c[i]='G';
            l-=b;
        }
    }
    cout<<c;
}