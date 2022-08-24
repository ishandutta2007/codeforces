#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >>n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    string s;
    cin >> s;
    int index = 0, grass = 0, water = 0, mx=0;
    int g=0, w=0, l=0;
    bool wwas = false;
    for (int i=0; i < n; i++){
        if (s[i] == 'G'){
            g += v[i];
        }
        else if (s[i] == 'W'){
            w += v[i];
            wwas = true;
        }
        else if (s[i] == 'L'){
            l += v[i];
            if (l - w - g > mx){
                mx = l-w-g;
                if (wwas) water = mx-grass;
                else grass = mx;
                index = i+1;
            }
        }
    }
    double ans = 3*water+5*grass;
    for (int i=0; i < n;i++){
        if (s[i] == 'W') ans += 3*v[i];
        if (s[i] == 'G') ans += 5*v[i];
        if (s[i] == 'L') ans += v[i];
    }
    double balance = 0;
    for (int i=index; i < n; i++){
        if (s[i] == 'L') balance -= v[i];
        else balance += v[i];
    }
    balance /= 2;
    double kek = balance, tet = balance;
    int cur = n-1;
    while (cur >= index){
        if (s[cur] == 'L'){
            tet += ((double) (v[cur]))/2.;
            cur--;
            continue;
        }
        if (s[cur] == 'W'){
            tet -= ((double)v[cur]) /2.;
            balance = min(balance, tet);
            cur--;
            continue;
        }
        if (v[cur] >= balance){
            ans -= 4*balance;
            kek -= balance;
            break;
        }
        tet -= ((double)v[cur]) /2.;
        ans -= 4*v[cur];
        kek -= v[cur];
        balance -= v[cur];
        balance = min(balance, tet);
        cur--;
    }
    ans -= 2*kek;
    int Ans = ans;
    cout << Ans;
    return 0;
}