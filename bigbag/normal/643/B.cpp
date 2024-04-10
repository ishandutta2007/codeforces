#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;
const int inf = 1001001001;

int n,k,a,b,c,d,p[1111111],ans;

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);

    cin >> n >> k >> a >> b >> c >> d;
    if (n==4){
        cout << -1;
        return 0;
    }
    if (k<n+1){
        cout << -1;
        return 0;
    }

    p[a]=1;
    p[b]=1;
    p[c]=1;
    p[d]=1;
    cout << a << ' ' << c << ' ';
    for (int i=1; i<=n; i++){
        if (p[i]==0) cout << i << ' ';
    }
    cout << d << ' ' << b << endl;
    cout << c << ' ' << a << ' ';
    for (int i=1; i<=n; i++){
        if (p[i]==0) cout << i << ' ';
    }
    cout << b << ' ' << d << endl;

    return 0;
}