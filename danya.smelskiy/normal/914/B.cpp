#include <bits/stdc++.h>
using namespace std;


int n;
int a[100005];
int kol[100005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        ++kol[a[i]];
    }
    for (int i=1;i<=n;++i) {
        int x=a[i];
        if (kol[x]&1) {
            cout<<"Conan";
            return 0;
        }
    }
    cout<<"Agasa";
}