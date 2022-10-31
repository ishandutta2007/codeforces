#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long shift[70] = {0};
    long long q; cin >> q;
    while(q--){
        long long t; cin >> t;
        if(t == 1){
            long long x, k; cin >> x >> k;
            shift[(long long)log2(x)] += k;
            shift[(long long)log2(x)+1] -= 2*k;
        }
        else if(t == 2){
            long long x, k; cin >> x >> k;
            shift[(long long)log2(x)] += k;
        }
        else{
            long long x; cin >> x;
            vector<long long> stuff;
            stuff.push_back(x);
            while(stuff.back() != 1){
                long long temp = (long long)log2(x);
                long long subtract = 1ll << temp;
                x -= subtract;
                x += shift[temp];
                x = ((x%subtract)+subtract)%subtract;
                x += subtract;
                x /= 2;
                stuff.push_back(x);
            }
            for(auto i : stuff){
                cout << i << " ";
            }
            cout << endl;
        }
    }
}