#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    char c='a';
    for(int i=0;i<n;i++){
        cout<<c;
        c=(c-'a'+1)%4+'a';
    }
}