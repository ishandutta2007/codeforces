#include <bits/stdc++.h>
using namespace std;
int a,b,ans;
int main(){
    cin>>a>>b;
    while (a>0 && b>0){
        if (a==1 && b==1) break;
        if (a<b){
            a++;
            b-=2;
        } else {
            a-=2;
            b++;
        }
        ++ans;
    }
    cout<<ans;
}