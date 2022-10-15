#include<bits/stdc++.h>
using namespace std;
 
string S;
int main(){
    cin>>S;
    int t = S.back() - '0';
    if (t  % 2 == 1)cout<<1;
    else cout<<0;
}