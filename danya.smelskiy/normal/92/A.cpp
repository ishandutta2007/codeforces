#include <bits/stdc++.h>
using namespace std;

long long n,m,now,ans;
int main(){
    cin>>n>>m;
    now=0;
    while (true){
        ++now;
        if (now>n) now=1;
        if (now+ans>m){
            cout<<m-ans;
            return 0;
        }
        ans+=now;
    }
}