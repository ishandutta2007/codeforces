#include<bits/stdc++.h>

using namespace std;

int t;
bool dp[1000];

int main(){
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        if(k%3==0){
            long long g=n%(3*k+3);
            long long f=0;
            if(g<k) f=0;
            else if(g<2*k)f=1;
            else if(g<3*k) f=2;
            else{
                cout<<"Alice\n";
                f=-1;
            } 
            if(f!=-1)cout<<((g-f+3)%3==0?"Bob\n":"Alice\n");/*
            if(n<k){
                cout<<(n%3==0?"Bob\n":"Alice\n");
            }else if(n<2*k){
                cout<<(n%3==1?"Bob\n":"Alice\n");
            }else{

            }*/
        }else{
            cout<<(n%3==0?"Bob\n":"Alice\n");
        }
    }

    return 0;
}