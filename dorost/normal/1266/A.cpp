#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int q;
    cin >> q;
    while(q--){
        string s;
        cin >> s;
        int n = s.size();
        bool f = false;
        int h = 0;
        int sum = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == '0'){
                f = true;
            }
            if ((s[i] - '0') % 2 == 0){
                h++;
            }
            sum += (s[i] - '0');
        }
        if ((f && h > 1 && sum % 3 == 0)){
            cout << "red";
        }else {
            cout << "cyan";
        }
        cout << endl;
    }
}