#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main(){
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    int x[3];
    cin >> x[0] >> x[1] >> x[2];
    
    int s = 0;
    for(int i = 0; i < 3; ++i){
        if(a[i] > x[i]){
            int k = a[i] - x[i];
            s += k/2;
        }
    }
    for(int i = 0; i < 3; ++i){
        if(x[i] > a[i]){
            int k = x[i] - a[i];
            if(k > s) {
                cout << "No" << endl;
                return 0;
            }
            s -= k;
        }
    }
    cout << "Yes" << endl;
}