#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    string a, b, s;
    cin >> a >> b >> s;
    for (int i = 0; i < s.size(); i++){
        for (int j = 0; j < 26; j++){
            if (s[i] == a[j]){
                s[i] = b[j];
                break;
            }else if(s[i] == a[j] + 'A' - 'a'){
                s[i] = b[j] + 'A' - 'a';
                break;
            }
        }
    }
    cout << s;
}