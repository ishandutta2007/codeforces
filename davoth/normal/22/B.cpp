#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const int N=2e5+10;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<pair<int,int>, null_type,less<pair<int,int> >, rb_tree_tag,tree_order_statistics_node_update>
ll n,m;
int main() {
    fast_io;
    cin >> n >> m;
    bool a[n][m];
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        for(int j=0; j<m; j++) a[i][j]=s[j]-'0';
    }
    /*bool b[n][m][m],c[n][m][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int k=0; k<m-j; k++){
                b[i][j][k] = !a[i][j + k] && (k == 0 || b[i][j][k - 1]);
            }
            for(int k=0; k<n-i; k++){
                c[i][j][k] = !a[i + k][j] && (k == 0 || c[i][j][k - 1]);
            }
        }
    }*/
    int ans=0,mxi=-1,mxj=-1,mxp=-1,mxq=-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int p=0; p<n-i; p++){
                for(int q=0; q<m-j; q++){
                    bool w=true;
                    for(int k=0; k<=i; k++){
                        for(int l=0; l<=j; l++) if(a[k+p][l+q]) w=false;
                    }
                    if(w && (i+j+2)*2>ans) ans=(i+j+2)*2,mxj=j,mxi=i,mxp=p,mxq=q;
                }
            }
        }
    }
    cout << ans;
    return 0;
}