#include <bits/stdc++.h>
#define MAXN 1000100
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define inf 1e18
#define fi first
#define se second
#define mt make_tuple
typedef long long ll;

using namespace std;

int n;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    while(n--){
        vi c(3), a(5);
        for(int i = 0; i < 3; i++)
            cin >> c[i];
        for(int i = 0; i < 5; i++)
            cin >> a[i];
        for(int i = 0; i < 3; i++)
            c[i] -= a[i];

        for(int i = 0; i < 2; i++){
            int p = max(0, min(a[i + 3], c[i]));
            c[i] -= p;
            a[i + 3] -= p;
            c[2] -= a[i + 3];
        }
        bool b = true;
        for(int i = 0; i < 3; i++){
            if(c[i] < 0){
                b = false;
            }
        }
        if(b) cout << "YES\n";
        else cout << "NO\n";
    }
}