#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main(){
    int n;
    cin >> n;
    vii V(n);
    
    for(int i = 0; i < n; ++i){
        V[i].second = i;
        cin >> V[i].first;
    }
    
    sort(V.begin(), V.end());
    
    int c = 0;
    int ant = 2*n;
    int m = 0;
    
    for(int i = 0; i < n; ++i){
        int k = V[i].second;
        
        if(ant < k){
            ant = k;
            ++c;
            m = max(m, c);
        }
        else {
            ant = k;
            m = max(m, c);
            c = 1;
        }
    }
    
    m = max(m, c);
    
    cout << n - m << endl;
}