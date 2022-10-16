//  228

//114A
#include<iostream>
#include<vector>
#include<string>
#define ll long long int 

using namespace std;

int main(){
    ll n,l,c=-1;
    cin>>n>>l;
    ll temp = n;
    while(l%n==0){
        l=l/n;
        c++;
    }
    if(l==1){
      
        cout<<"YES"<<endl<<c<<endl;
    }
    else{
   
        cout<<"NO"<<endl;
    }
}