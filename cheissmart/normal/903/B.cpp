#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int h1, a1, c1, h2, a2;
    vector<bool> v;
    cin >> h1 >> a1 >> c1 >> h2 >> a2;
    while(h2 > 0){
        if(h1<=a2 && h2>a1) {
            v.push_back(false);
            h1 += c1;
            h1 -= a2;
        } else {
            v.push_back(true);
            h1 -= a2;
            h2 -= a1;
        }
    }
    cout << v.size() << endl;
    for(int i=0;i<v.size();i++) cout << (v[i] ? "STRIKE" : "HEAL") << endl;
}