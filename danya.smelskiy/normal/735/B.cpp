#include <bits/stdc++.h>
using namespace std;
long double k,k1,sum1,sum2,sz1,sz2;
long long n,a[100001];
inline bool cmp(long double a,long double b){
    return a<b;
}
int main(){
    cin>>n>>k>>k1;
    for (int i=1;i<=n;++i)
        cin>>a[i];
       if (k1<k) swap(k1,k);
    sort(a+1,a+n+1,cmp);
    for (int j=n;j>0;--j){
        if (sz1==k && sz2==k1) break;
        if (sz1<k){
            sum1+=a[j];
            ++sz1;
        } else
        if (sz2<k1){
            sum2+=a[j];
            ++sz2;
        }
    }
    cout<<fixed<<setprecision(20)<<sum1/sz1+sum2/sz2;
}