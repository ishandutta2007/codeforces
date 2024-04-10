#include <bits/stdc++.h>
using namespace std;

int n;
long long x;
long double sum,y;
long double a[200005];
long double ob[200005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    int sz=1;
    cout<<fixed<<setprecision(6);
    int tp;
    while (n--) {
        cin>>tp;
        if (tp==1) {
            cin>>x>>y;
            ob[x]+=y;
            sum+=(x*y);
        } else if (tp==2) {
            cin>>x;
            ++sz;
            a[sz]=x;
            sum+=x;
        } else {
            ob[sz-1]+=ob[sz];
            sum-=ob[sz]+a[sz];
            ob[sz]=a[sz]=0;
            --sz;
        }
        cout<<sum/sz<<'\n';
    }
}