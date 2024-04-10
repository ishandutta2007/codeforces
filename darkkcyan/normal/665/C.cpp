#include <bits/stdc++.h>

using namespace std;

#ifdef db 
#define de(msg) cerr << "line " << __LINE__ << " => " << msg << '\n'
#else
#define de(msg)
#define at operator[]
#endif

#define dev(var) de(#var << ' ' << var)
#define _ << ' ' <<

#define fi first
#define se second
#define mp make_pair
#define ll long long 
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front

#define pii pair<int, int>
#define pilll pair<int, ll>
#define pllll pair<ll, ll>

#define ve vector
#define vi ve<int>
#define vll ve<ll>

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ap(a, b, p) {a = (p).fi; b = (p).se;}

char d(char a, char b) {
    if (a > b) swap(a, b);
    if (a == 'a') {
        if (b == 'b') return 'c';
        return 'b';
    }
    return 'a';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int i, f, g;  // count variable

    string str;
    cin >> str;

    for (i = 1; i < str.size(); ++i) {
        if (str[i] != str[i - 1]) continue;
        str[i] = d(str[i - 1], i == str.size() - 1? str[i - 1] : str[i + 1]);
    }

    cout << str;
    return 0;
}