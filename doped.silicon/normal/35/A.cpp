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
using namespace std;
 
int main(){
    FAST;FASTT;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int ar[3]={0},c,a,b;
    cin>>c;
    ar[c-1]=1;
    for(int i=0;i<3;i++){
        cin>>a>>b;
        swap(ar[a-1],ar[b-1]);
    }
    if(ar[0]==1){cout<<1<<endl;}
    else if(ar[1]==1){cout<<2<<endl;}
    else{cout<<3<<endl;}
}