#include <iostream>
using namespace std;
string s[6] = {"170", "020", "200", "110", "050", "080"};
int main(){
    int n;
    cin >> n;
    if(n < 3) cout << - 1 << endl;
    else if(n==3) cout << 210 << endl;
    else{
        cout << 1;
        for(int i = 0; i < n-4; i++) cout << 0;
        cout << s[n%6] <<endl;
    }
    return 0;
}