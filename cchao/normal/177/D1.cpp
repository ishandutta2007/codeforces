#include <iostream>
#define N 100000
using namespace std;
typedef long long ll;
int main(){
    ll n,m,c;
    cin >> n >> m >> c;
    ll a[N],b[N],f[N],r[N];
    ll k,j;
    for(k=0;k<n;k++) cin >> a[k];
    for(k=0;k<m;k++) cin >> b[k];

    for(k=0;k+m-1<n;k++)
        for(j=0;j<m;j++){
            //cout << 'a' << j+k << " add b" << j << endl; 
            a[k+j] += b[j];
            a[k+j] %= c;
        }
    
    for(k=0;k<n;k++) cout << a[k] << ' ';
    cout << endl;

    return 0;
}