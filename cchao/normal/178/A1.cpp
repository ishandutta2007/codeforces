#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin >> n;
    ll a[n];
    ll bit[100000];
    for(ll k=n-1;k>=0;k--){
        ll i=1,tmp=0;
        while(i<=k){
            if(i&k) tmp++;
            i<<=1;
        }
        //if(k<n-1 && tmp>bit[k+1]) tmp=bit[k+1];
        bit[k]=tmp;
    }
//    cout << "---" << endl;
//    for(ll k=0;k<n;k++) cout << bit[k] << ' ';
//    cout << endl << "----" << endl;
    for(ll k=0;k<n;k++) cin >> a[k];
    for(ll k=0;k<n-1;k++){
        ll times=0;
        for(ll i=0;i<=k;i++){
            ll mi=2000000000;
            for(ll t=k+1-i;i+t<n;t++) if(bit[t] < mi) mi=bit[t];
            //cout << "times add " << a[i]*mi << endl;
            times += a[i]*mi;
        }
        cout << times << endl;
    }
    return 0;
}