#include<iostream>
#include<vector>
using namespace std;

int main(){

    int n, x;

    cin>>n>>x;

    int S = 0;

    for(int i = 0; i<n; ++i){
        int y;
        cin>>y;
        S += y;
    }

if (S < 0)S =- S;

int u = S/x;
if (x*u != S) ++u;

cout<<u;


}