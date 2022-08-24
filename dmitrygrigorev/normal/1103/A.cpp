#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    bool isv = false, ist = false;
    for (int i=0; i < s.size(); i++){
        if (s[i] == '0'){
            if (!isv){
                cout << "1 1" << endl;
                isv = true;
            }
            else{
                cout << "3 1" << endl;
                isv = false;
            }
        }
        else{
            if (!ist){
                cout << "4 3" << endl;
                ist = true;
            }
            else{
                cout << "4 1" << endl;
                ist = false;
            }
        }
    }
}