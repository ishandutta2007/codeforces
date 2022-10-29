#include <iostream>
#include <bits/stdc++.h>
#include <iomanip>
typedef long long int lli;
#define FAST ios_base::sync_with_stdio(false);
#define FASTT cin.tie(NULL);
#define pb push_back
#define pf push_front
#define mp make_pair
#define ff first
#define ss second
#define ap append
using namespace std;
 
int main(){
    FAST;FASTT;
    int t;
    string f("lala."),r("miao."),s;
    cin>>t;
    getline(cin, s);
    for(int i=1;i<=t;i++){
        getline(cin, s);
        int n=s.size();
        if(n<5){cout<<"OMG>.< I don't know!"<<endl;}
        else{
            bool haha=0,flag=0;
            if(s.substr(0,5)==r){haha=1;}
            if(s.substr(n-5,5)==f){flag=1;}
            if(flag && haha){
                cout<<"OMG>.< I don't know!"<<endl;
            }
            else if(haha){
                cout<< "Rainbow's" <<endl;
            }
            else if(flag){
                cout<<"Freda's" <<endl;
            }
            else{
                cout<<"OMG>.< I don't know!"<<endl;
            }
        }
    }
}