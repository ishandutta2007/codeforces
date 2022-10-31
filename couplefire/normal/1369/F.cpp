#include <iostream>
#include <vector>
#include <string>
#define fr first
#define sc second
#define ll long long
#define int ll

using namespace std;

const int MN = 1e5+7;

pair<int, int> c[MN];

int chk(ll s, ll e){
    if(e == s)return 0;
    if(e == s+1)return 1;
    if(e & 1){
        if(s & 1)return 0;
        return 1;
    }
    if(s <= e/4)
        return chk(s, e/4);
    if(s > (e/4)*2)return ((e-s)&1);
    else return 1;
}

int lck(ll s, ll e){
    if(s*2 > e)return 1;
    int w = e/2 + 3;
    while(w*2 > e)w--;
    return chk(s, w);
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        c[i] = {chk(x, y), lck(x, y)};
    }

    int f = 1;
    int s = 0;
    for(int i = 0; i < n; i++){
        if(f == 1 && s == 1)break;
        if(f == 0 && s == 0)break;
        if(s == 1) c[i].fr^=1, c[i].sc^=1;
        f = c[i].sc;
        s = c[i].fr;
    }
    cout << s << ' ' << f << '\n';
}