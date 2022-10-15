#include<bits/stdc++.h>
using namespace std;
 
int a;
int main(){
    cin>>a;
    int x=0;
    for (int i=1;i*i<=a;++i){
        if (a%i==0)x=i;
    }
    cout<<x<<a/x;
}