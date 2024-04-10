#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
#define piii              pair<int,pii>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int a[2100][2100];
int b[5000],c[5000];
void solve(){
    int n,e=0,o=0;pii ee={1,1},oo={1,2};
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            b[i+j]+=a[i][j];
            c[n+i-j]+=a[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if((i+j)%2==0){
                int t=b[i+j]+c[n+i-j]-a[i][j];
                if(t>e){
                    ee={i+1,j+1};
                    e=t;
                }
            }
            else{
                int t=b[i+j]+c[n+i-j]-a[i][j];
                if(t>o){
                    oo={i+1,j+1};
                    o=t;
                }
            }
        }
    }
    cout<<(e+o)<<"\n";
    cout<<ee.fr<<" "<<ee.sc<<" "<<oo.fr<<" "<<oo.sc;
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}