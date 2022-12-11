#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main(){
    int n, m;
    cin >> n >> m;
    
    vii A(m);
    vii R(m);
    for(int i = 0; i < m; ++i){
        cin >> A[i].first;
        int k;
        cin >> k;
        if(k) A[i].second = -(i + 1);
        else A[i].second = (i + 1);
    }
    
    sort(A.begin(), A.end());
    
    int x = 1;
    int y = 1;
    int l = 0;
    for(int i = 0; i < m; ++i){
        int k = A[i].second;
        if(k < 0){
            ++k;
            k = -k;
            R[k].first = ++l;
            R[k].second = 0;
        }
        else {
            --k;
            if(x == y){
                ++x;
                y = 1;
            }
            if(x > l){
                cout << -1 << endl;
                return 0;
            }
            R[k].first = x;
            R[k].second = y;
            ++y;
        }
    }
    
    for(int i = 0; i < m; ++i){
        cout << R[i].first+1 << " " << R[i].second+1 << endl;
    }
}