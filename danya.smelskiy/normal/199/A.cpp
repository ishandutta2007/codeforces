#include <bits/stdc++.h>
using namespace std;

long long n;
long long f[100];
long long q[100];
int sz;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    f[1]=1;
    sz=1;
    while (true) {
        ++sz;
        f[sz]=f[sz-1]+f[sz-2];
        if (f[sz]>1e9) {
            --sz;
            break;
        }
    }
    int kol=0;
    for (int i=sz;i>0;--i) {
        while (f[i]<=n) {
            n-=f[i];
            q[++kol]=f[i];
        }
    }
    if (kol>3) {
        cout<<"I'm too stupid to solve this problem";
        return 0;
    }
    kol=3;
    for (int i=kol;i>0;--i)
        cout<<q[i]<<" ";
}