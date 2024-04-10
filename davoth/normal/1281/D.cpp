#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 2e5 + 10;
int main() {
    fast_io;
    int t;
    cin >> t;
    while(t--){
        int r,c;
        cin >> r >> c;
        string a[r];
        for(int i=0; i<r; i++){
            string s;
            cin >> s;
            a[i]=s;
        }
        bool ck=false;
        for(int i=0; i<r; i++) for(int j=0; j<c; j++){
            if(a[i][j]=='A'){
                ck=true;
                break;
            }
        }
        if(!ck) {
            cout << "MORTAL\n";
            continue;
        }
        ck=false;
        for(int i=0; i<r; i++) for(int j=0; j<c; j++){
            if(a[i][j]=='P'){
                ck=true;
                break;
            }
        }
        if(!ck){
            cout << 0 << '\n';
            continue;
        }
        ck=false;
        for(int i=0; i<c; i++){
            if(a[0][i]=='P') ck=true;
        }
        if(!ck){
            cout << 1 << '\n';
            continue;
        }
        ck=false;
        for(int i=0; i<c; i++){
            if(a[r-1][i]=='P') ck=true;
        }
        if(!ck){
            cout << 1 << '\n';
            continue;
        }
        ck=false;
        for(int i=0; i<r; i++){
            if(a[i][0]=='P') ck=true;
        }
        if(!ck){
            cout << 1 << '\n';
            continue;
        }
        ck=false;
        for(int i=0; i<r; i++){
            if(a[i][c-1]=='P') ck=true;
        }
        if(!ck){
            cout << 1 << '\n';
            continue;
        }
        for(int i=0; i<r; i++){
            ck=false;
            for(int j=0; j<c; j++){
                if(a[i][j]=='P') ck=true;
            }
            if(!ck){
                cout << 2 << '\n';
                break;
            }
        }
        if(!ck) continue;
        for(int i=0; i<c; i++){
            ck=false;
            for(int j=0; j<r; j++){
                if(a[j][i]=='P') ck=true;
            }
            if(!ck){
                cout << 2 << '\n';
                break;
            }
        }
        if(!ck) continue;
        if(a[0][0]=='A' || a[0][c-1]=='A' || a[r-1][0]=='A' || a[r-1][c-1]=='A'){
            cout << 2 << '\n';
            continue;
        }
        ck=true;
        for(int i=0; i<c; i++){
            if(a[0][i]=='A' || a[r-1][i]=='A'){
                cout << 3 << '\n';
                ck=false;
                break;
            }
        }
        if(!ck) continue;
        ck=true;
        for(int i=0; i<r; i++){
            if(a[i][0]=='A' || a[i][c-1]=='A'){
                cout << 3 << '\n';
                ck=false;
                break;
            }
        }
        if(!ck) continue;
        cout << 4 << '\n';
    }
    return 0;
}