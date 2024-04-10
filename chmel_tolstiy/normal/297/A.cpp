#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int  main() {
   string a, b;
   cin >> a >> b;
   int A = count(a.begin(), a.end(), '1');
   int B = count(b.begin(), b.end(), '1');
   A += A % 2;

   cout << ((A >= B) ? ("YES") : ("NO")) << endl;
   return 0;
}