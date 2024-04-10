#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define DEBUG(x) cout<<"["<<#x<<" : "<<x<<"]\n"
#define DEBUG2(x, y) cout<<"["<<#x<<" : "<<x<<"]"<<"  ["<<#y<<" : "<<y<<"]\n"
#define DEBUG3(x, y, z) cout<<"["<<#x<<" : "<<x<<"]"<<"  ["<<#y<<" : "<<y<<"]"<<"  ["<<#z<<" : "<<z<<"]\n"
#define DEBUG4(x, y, z, k) cout<<"["<<#x<<" : "<<x<<"]"<<"  ["<<#y<<" : "<<y<<"]"<<"  ["<<#z<<" : "<<z<<"]"<<"  ["<<#k<<" : "<<k<<"]\n"

const int N = 1e6 + 9;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>> n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>> a[i];
    ll m;
    cin>> m;
    vector<ll> b(m);
    for(int i=0; i<m; i++) cin>> b[i];
    ll sa = 0, sb = 0;
    for(ll e: a) sa += e;
    for(ll e: b) sb += e;
    if(sa != sb) cout<< -1;
    else{
        ll ans = 0;
        for(int i=0, j=0; i<m && j<n; i++, j++){
            sa = a[j];
            sb = b[i];
            //DEBUG2(sa, sb);
            while(sa != sb){
                while(sa < sb){
                    j++;if(j==n) break;
                    sa += a[j];
                }
                while(sb < sa){
                    i++; if(i==m) break;
                    sb += b[i];
                }
                //DEBUG2(sa, sb);
                if(i==m || j==n) break;
            }
            ans++;
        }
        cout<< ans;
    }
}