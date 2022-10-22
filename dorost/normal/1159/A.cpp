#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
    cin >> n;
    char c;
    int ans = 0, a = 0;
    for(int i = 0; i < n; i++){
        cin >> c;
        if(c == '-'){
            a--;
        }else {
            a++;
        }
        ans = min(ans, a);
    }
    cout << -ans + a;
}