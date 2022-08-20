#include <iostream>

using namespace std;

int main() {
int t,s,x;
cin >> t >> s >> x;
if (t > x) {
cout << "NO";
return 0;
}
if ((x-t) % s <= 1) {
if (x == (t+1)) cout << "NO";
else cout << "YES";
} else cout << "NO";
}