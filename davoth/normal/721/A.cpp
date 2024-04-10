#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s.push_back('W');
    int r=0;
    vector<int> a;
    int m=0;
    for(int i=0; i<n+1; i++){
        if(s[i]=='B') m++;
        else if(m){
            r++;
            a.push_back(m);
            m=0;

        }
    }
    cout << r << '\n';
    for(int i=0; i<r; i++){
        cout << a[i] << ' ';
    }
    return 0;
}