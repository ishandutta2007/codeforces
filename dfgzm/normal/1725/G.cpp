#include<bits/stdc++.h>
using namespace std;
int i,j,k,n,m;
int main(){
    cin>>n;
    if(n==1)cout<<3<<endl;
    else if(n==2)cout<<5<<endl;
    else if(n==3)cout<<7<<endl;
    else cout<<7+(n-3)+(n-3)/3<<endl;
}
/*
7 3
8 4
9 5

11 6
12 7
13 8
*/