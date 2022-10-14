#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int Bc = 0, Sc = 0, Cc = 0;
    string s; cin >> s;
    for(char c:s) {
        if(c == 'B') Bc++;
        if(c == 'S') Sc++;
        if(c == 'C') Cc++;
    }
    int Bo, So, Co; cin >> Bo >> So >> Co;
    int Bp, Sp, Cp; cin >> Bp >> Sp >> Cp;
    long long money; cin >> money;
    long long left = 0, right = money+301, ans = -1;
    while(left <= right) {
        long long mid = (left+right) >> 1;
        long long Bt = Bc*mid, St = Sc*mid, Ct = Cc*mid;
        Bt -= Bo; St -= So; Ct -= Co;
        Bt = max(Bt, 0ll); St = max(St, 0ll); Ct = max(Ct, 0ll);
        if(Bt*Bp + St*Sp + Ct*Cp <= money) { left = mid+1; ans = mid; }
        else right = mid-1;
    }
    cout << ans << endl;
}