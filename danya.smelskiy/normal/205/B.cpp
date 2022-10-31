#include <bits/stdc++.h>
using namespace std;




int n;
long long a[100005];


int main() {
//    freopen("school.in","r",stdin);
  //  freopen("school.out","w",stdout);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    long long mx=0;
    long long cur=0;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        a[i]+=cur;
        if (a[i]>=mx) {
            mx=a[i];
            continue;
        }
        cur+=mx-a[i];
    }
    cout<<cur;

}