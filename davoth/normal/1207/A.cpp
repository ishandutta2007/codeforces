#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--){
        int b,p,f,profit=0;
        cin >> b >> p >> f;
        b/=2;
        int h,c;
        cin >> h >> c;
        if(h>c){
            profit+=min(b,p)*h;
            b-=min(b,p);
            profit+=min(b,f)*c;
        }else{
            profit+=min(b,f)*c;
            b-=min(b,f);
            profit+=min(b,p)*h;
        }
        cout << profit << '\n';
    }
    return 0;
}