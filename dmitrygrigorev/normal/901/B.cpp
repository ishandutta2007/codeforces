#include<bits/stdc++.h>
using namespace std;
#define int long double
int eps = 0.00000001;
struct Mn{int num; vector<int> v;};
Mn del(Mn a, Mn b){
    int diff = a.num - b.num + 1;
    for (int i=0; i < diff; i++){
        int degree = a.num - i;
        int raz = degree - b.num;
        int st = a.v[degree] / b.v[b.num];
        for (int j=0; j <= b.num; j++){
            int now = j+raz;
            int coeff = st * b.v[j];
            a.v[now] -= coeff;
        }
    }
    int old = a.num;
    for (int i=a.num; i >= 0; i--){
        if (abs(a.v[i]) > eps){
            a.num = i;
            break;
        }
    }
    if (a.num == old) a.num = 0;
    return a;
}
int gcd(Mn a, Mn b){
    if (b.num == 0 && abs(b.v[0]) < eps) return 0;
    Mn res = del(a, b);
    return gcd(b, res) + 1;
}
signed main(){
    int n;
    cin >> n;
    srand(time(NULL));
    while (true){
        Mn f, s;
        f.num = -1;
        s.num = -1;
        vector<int> a, b;
        for (int i=0; i < n; i++){
            int X = rand() % 2;
            int Y = rand() % 2;
            if (X == 0) a.push_back(1);
            if (X == 1) a.push_back(-1);
            if (X == 2) a.push_back(0);
            if (i != n-1){
                if (Y == 0) b.push_back(1);
                if (Y == 1) b.push_back(-1);
                if (Y == 2) b.push_back(0);
            }
        }
        a.push_back(1);
        b.push_back(1);
        f.v = a;
        s.v = b;
        for (int i=n; i >= 0; i--){
            if (f.v[i] != 0){
                f.num = i;
                break;
            }
        }
        for (int i=n-1; i >= 0; i--){
            if (s.v[i] != 0){
                s.num = i;
                break;
            }
        }
        Mn f1 = f, s1 = s;
        int g = gcd(f, s);
        if (g == n){
            cout << f1.num << endl;
            for (int i=0; i <= f1.num; i++) cout << f1.v[i] << " ";
            cout << endl;
            cout << s1.num << endl;
            for (int i=0; i <= s1.num; i++) cout << s1.v[i] << " ";
            cout << endl;
            return 0;
        }
    }
    return 0;
}