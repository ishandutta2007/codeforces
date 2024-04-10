#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    cout << fixed << setprecision(0);
    long long l,r, k; cin >> l >> r >> k;
    if(r - l + 1 < 7){
        long long mi = r+1;
        long long core = -1;
        for(long long i = 1; i<pow(2, r-l+1); i++){
            long long num = __builtin_popcountll(i);
            if(num > k) continue;
            long long temp = 0;
            for(long long j = 0; j<r-l+1; j++){
                if(i & (1 << j)) temp ^= l+j;
            }
            if(temp < mi){
                mi = temp;
                core = i;
            }
        }
        cout << mi << endl;
        cout << __builtin_popcountll(core) << endl;
        for(long long i = 0; i<r-l+1; i++){
            if(core & (1 << i)) cout << l+i << " ";
        }
        cout << endl;
        exit(0);
    }
    if(k >= 4){
        long long t = ceil(l/4.0)*4;
        cout << 0 << endl;
        cout << 4 << endl;
        cout << t << " " << t+1 << " " << t+2 << " " << t+3 << endl;
        exit(0);
    }
    if(k == 3){
        for(long long i = 1; i<50; i++){
            if(pow(2, i)-1 >= l && pow(2, i)+pow(2, i-1) <= r){
                cout << 0 << endl;
                cout << 3 << endl;
                cout << pow(2, i)-1 << " " << pow(2, i)+pow(2, i-1)-1 << " " << pow(2, i)+pow(2, i-1) << endl;
                exit(0);
            }
        }
    }
    if(k >= 2){
        long long t = ceil(l/2.0)*2;
        cout << 1 << endl;
        cout << 2 << endl;
        cout << t << " " << t+1 << " " << endl;
        exit(0);
    }
    cout << l << endl;
    cout << 1 << endl;
    cout << l << endl;
}