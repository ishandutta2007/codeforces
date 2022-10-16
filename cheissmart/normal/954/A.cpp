#include <iostream>

using namespace std;

int main()
{
    int n, ans = 0;
    string s;
    cin >> n >> s;
    ans = n;
    for(int i=0;i<n-1;i++) {
        if(s[i]+s[i+1] == 'U'+'R') {
            ans -= 1;
            i++;
        }
    }
    cout << ans << endl;
}