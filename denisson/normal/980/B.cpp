#include <bits/stdc++.h>
//#pragma comment(linker, /STACK:36777216)
           
using namespace std;
           
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n, m;


int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    cout << "YES\n";
    for (int i = 0; i < n; i++) cout << '.'; cout << endl;
    if (m % 2 == 0){
        cout << '.';
        int val = m / 2;
        for (int i = 0; i < n - 2; i++){
            if (val) cout << "#", val--;
            else cout << '.';
        }
        cout << '.'; cout << endl;
        cout << '.';
        val = m / 2;
        for (int i = 0; i < n - 2; i++){
            if (val) cout << "#", val--;
            else cout << '.';
        }
        cout << '.'; cout << endl;
    } else {
        if (m <= n - 2){
            int cc = (n - 2 - m) / 2;

            cout << '.';
            for (int i = 0; i < n - 2; i++){
                if (cc){
                    cc--;
                    cout << '.';
                } else if (m){
                    m--;
                    cout << '#';
                } else cout << '.';
            }
            cout << '.'; cout << endl;


            cout << '.';
            for (int i = 0; i < n - 2; i++){
                cout << ".";
            }
            cout << '.'; cout << endl;
        } else {
            cout << '.';
            for (int i = 0; i < n - 2; i++){
                cout << "#";
            }
            cout << '.'; cout << endl;
            m -= n - 2;

            int cc = m / 2;
            int cc2 = n - 2 - m;
            cout << '.';
            for (int i = 0; i < n - 2; i++){
                if (cc){
                    cc--;
                    cout << '#';
                } else if (cc2){
                    cc2--;
                    cout << '.';
                } else cout << '#';
            }
            cout << '.'; cout << endl;
        }
    }
    for (int i = 0; i < n; i++) cout << '.'; cout << endl;
}