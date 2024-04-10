//  228

//https://codeforces.com/contest/9/problem/A

#include<iostream>
using namespace std;

int gcd(short int a,short int b) {
    if(a*b==0)
        return max(a,b);
    else
        return gcd(a+b-2*min(a,b),min(a,b));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    short int Y,W;
    cin>>Y>>W;
    short int A=7-max(W,Y);
    if(A==6)
        cout<<"1/1";
    else {
        cout<<A/gcd(A,6)<<"/"<<6/gcd(A,6);
    }
}