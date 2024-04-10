#include <iostream>
#include <string>

using namespace std;
string s, t;
int n, k, pos;

int main()
{
    cin >> n >> k;
    cin >> t;
    pos=1;
    while(t.substr(pos, n-pos)!=t.substr(0, n-pos))
        pos++;
    cout << t;
    for(int i=1;i<k;i++)
        cout << t.substr(n-pos, pos);
    return 0;
}