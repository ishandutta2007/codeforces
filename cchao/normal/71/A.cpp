#include <iostream>
using namespace std;
int main()
{
    int n;
    string s;
    cin >> n;
    while(n--){
        cin >> s;
        if(s.length()<=10) cout << s << endl;
        else{
            cout << s[0] << s.length()-2 << s[s.length()-1] << endl;
        }
    }
    return 0;
}