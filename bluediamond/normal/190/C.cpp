#include <bits/stdc++.h>

using namespace std;

const int N = 100000 + 5;

int n, need, have = 0;
string a[N], ans;
int poz = 1;

inline void go() {;
    if (a[poz] == "int") {
        ans += "int";
        poz++;
        return;
    }
    if (poz > n) return;
    ans += "pair<";
    poz++, go();
    ans += ",";
    go();
    ans += ">";
}

int st[N], vf = 0;

inline void e() {
    cout<<"Error occurred\n";
    exit(0);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>need;
    string b;
    while(cin>>b) {
        n++;
        a[n] = b;
        if (a[n] == "int") have++;
    }
    if(vf && a[vf]=="pair") e();
    if (need == 1) {
        if (n == 1) cout<<"int\n";
        else e();
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == "pair") {
            st[++vf] = 1;
            continue;
        }
        if (vf == 0) e();
        st[++vf] = 2;
        while (vf >= 2 && st[vf] == 2 && st[vf - 1]==2) {
            vf -= 2;
            if (vf == 0 || st[vf] == 2) e();
            st[vf] = 2;
        }
    }
    if (vf == 1 && st[1] == 2)
        go();
    else
        e();
    cout<<ans<<"\n";
    return 0;
}
/**



**/