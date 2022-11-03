#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG
ifstream input_from_file("input.txt");
#define cin input_from_file
#endif

typedef long long LL;
typedef pair<int, int> II;

int q[4];
int T;
int S;
vector<int> A;
vector<int> B;
vector<int> N;
int ans;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n; cin >> n;
    int a = 0, b = 0;
    
    for(int i=0; i<n; i++){
        string s; cin >> s;
        int x; cin >> x;
        if(s == "00") {N.push_back(x);}
        if(s == "01") {B.push_back(x); T += x; b++;}
        if(s == "10") {A.push_back(x); T += x; a++;}
        if(s == "11") {T += x; S += 1;}
    }
    
    sort(N.begin(), N.end()); reverse(N.begin(), N.end());
    sort(B.begin(), B.end()); reverse(B.begin(), B.end());
    sort(A.begin(), A.end()); reverse(A.begin(), A.end());
    
    ans = 0;
    
    for(int y=0; y<=(int)N.size(); y++){
        if(S - y < 0){cout << ans << '\n'; return 0;}
        while(a - b > S - y){a--; if(a < 0){cout << ans << '\n'; return 0;} T -= A[a]; }
        while(b - a > S - y){b--; if(b < 0){cout << ans << '\n'; return 0;} T -= B[b]; }
        
        //~ cerr << y << ' ' << S-y << ' ' << T << endl;
        ans = max(ans, T);
        
        if(y < (int)N.size()){
            T += N[y];
        }
    }
    cout << ans << '\n';
}