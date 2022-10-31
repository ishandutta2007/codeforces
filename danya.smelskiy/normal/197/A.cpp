#include <bits/stdc++.h>
using namespace std;

int n,m,r;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>r;
    if (r+r>min(n,m)) cout<<"Second";
    else cout<<"First";
}