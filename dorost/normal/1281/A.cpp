#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
   int n;
   cin >> n;
   for (int i = 0; i < n; i++){
        string s,j1 = "desu",j2 = "masu", k = "masu";
        cin >> s;
        int n = s.size(),js = j1.size(),ks = k.size();
        if (s[n - 1] == 'o' && s[n - 2] == 'p'){
            cout << "FILIPINO";;
        }else{
            bool d1 = true, d2 = true;
            int c = 0;
            for (int j = n - js; j < n; j++){
                if (s[j] != j1[c]){
                    d1 = false;
                }
                if (s[j] != j2[c]){
                    d2 = false;
                }
                c++;
            }
            if (d1 || d2){
                cout << "JAPANESE";
            }else {
                cout << "KOREAN";
            }
        }
        cout << endl;
   }
}