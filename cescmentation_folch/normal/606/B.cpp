#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main(){
    int x, y, x0, y0;
    cin >> x >> y >>x0 >> y0;
    --x0;
    --y0;
    vvi M(x, vi(y, 0));
    
    string a;
    cin >> a;
    int res[a.size() + 1];
    
    res[0] = 1;
    M[x0][y0] =1;
    int tt = x*y - 1;
    
    for(int i = 0; i < a.size(); ++i){
        if(a[i] == 'U'){
            if(x0 > 0) --x0;
        }
        else if(a[i] == 'D'){
            if(x0 < x-1) ++x0;
        }
        else if(a[i] == 'R'){
            if(y0 < y-1) ++y0;
        }
        else {
            if(y0 > 0) --y0;
        }
        if(M[x0][y0] == 0){
            M[x0][y0] = 1;
            res[i+1] = 1;
            --tt;
        }
        else res[i+1] = 0;
    }
    res[a.size()] += tt;
    
    for(int i = 0; i <= a.size(); ++i) cout << (i? " " : "") << res[i];
    cout << endl;
}