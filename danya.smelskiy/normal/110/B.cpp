#include <bits/stdc++.h>
using namespace std;

int n;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=0;i<n;++i)
        cout<<char('a'+i%4);
}