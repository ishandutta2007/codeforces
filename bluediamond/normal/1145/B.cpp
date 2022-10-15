/**
 Builded using Code Generator :
 #include <bits/stdc++.h>

using namespace std;



int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen ("input", "r", stdin);
  freopen ("output", "w", stdout);

  cout << "#include <bits/stdc++.h>\n\n";
  cout << "using namespace std;\n\n";
  cout << "int main() {\n";
  cout << "  ios::sync_with_stdio(false); \n";
  cout << "  cin.tie(0); \n\n";
  cout << "  int a;\n";
  cout << "  cin >> a;\n\n";
  cout << "  bool ok = 0;\n";
  cout << "  string yes; yes += 'Y', yes += 'E', yes += 'S';\n";
  cout << "  string no; no += 'N', no += 'O';\n\n";
  for (int i = 0; i <= 100; i++) {
    char s[100];
    cin.getline(s, 100);
    int n = strlen(s);
    bool ok = 1;
    for (int j = 0; j < n; j++) {
      if (s[j] == 'k' || s[j] == 'a' || s[j] == 'n') {
        ok = 0;
      }
    }
    if (ok) {
      cout << "  if (a == " << i << ") {\n";
      cout << "    ok = 1; \n";
      cout << "    cout << yes; \n";
      cout << "  }\n";
    }
  }
  cout << "  if (ok == 0) {\n";
  cout << "  cout << no;\n";
  cout << "  }\n";
  cout << "  cout << endl;\n";
  cout << "  return 0;\n";
  cout << "}";
}
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a;
  cin >> a;

  bool ok = 0;
  string yes; yes += 'Y', yes += 'E', yes += 'S';
  string no; no += 'N', no += 'O';

  if (a == 0) {
    ok = 1;
    cout << yes;
  }
  if (a == 2) {
    ok = 1;
    cout << yes;
  }
  if (a == 3) {
    ok = 1;
    cout << yes;
  }
  if (a == 4) {
    ok = 1;
    cout << yes;
  }
  if (a == 5) {
    ok = 1;
    cout << yes;
  }
  if (a == 6) {
    ok = 1;
    cout << yes;
  }
  if (a == 8) {
    ok = 1;
    cout << yes;
  }
  if (a == 12) {
    ok = 1;
    cout << yes;
  }
  if (a == 30) {
    ok = 1;
    cout << yes;
  }
  if (a == 32) {
    ok = 1;
    cout << yes;
  }
  if (a == 33) {
    ok = 1;
    cout << yes;
  }
  if (a == 34) {
    ok = 1;
    cout << yes;
  }
  if (a == 35) {
    ok = 1;
    cout << yes;
  }
  if (a == 36) {
    ok = 1;
    cout << yes;
  }
  if (a == 38) {
    ok = 1;
    cout << yes;
  }
  if (a == 40) {
    ok = 1;
    cout << yes;
  }
  if (a == 42) {
    ok = 1;
    cout << yes;
  }
  if (a == 43) {
    ok = 1;
    cout << yes;
  }
  if (a == 44) {
    ok = 1;
    cout << yes;
  }
  if (a == 45) {
    ok = 1;
    cout << yes;
  }
  if (a == 46) {
    ok = 1;
    cout << yes;
  }
  if (a == 48) {
    ok = 1;
    cout << yes;
  }
  if (a == 50) {
    ok = 1;
    cout << yes;
  }
  if (a == 52) {
    ok = 1;
    cout << yes;
  }
  if (a == 53) {
    ok = 1;
    cout << yes;
  }
  if (a == 54) {
    ok = 1;
    cout << yes;
  }
  if (a == 55) {
    ok = 1;
    cout << yes;
  }
  if (a == 56) {
    ok = 1;
    cout << yes;
  }
  if (a == 58) {
    ok = 1;
    cout << yes;
  }
  if (a == 60) {
    ok = 1;
    cout << yes;
  }
  if (a == 62) {
    ok = 1;
    cout << yes;
  }
  if (a == 63) {
    ok = 1;
    cout << yes;
  }
  if (a == 64) {
    ok = 1;
    cout << yes;
  }
  if (a == 65) {
    ok = 1;
    cout << yes;
  }
  if (a == 66) {
    ok = 1;
    cout << yes;
  }
  if (a == 68) {
    ok = 1;
    cout << yes;
  }
  if (a == 80) {
    ok = 1;
    cout << yes;
  }
  if (a == 82) {
    ok = 1;
    cout << yes;
  }
  if (a == 83) {
    ok = 1;
    cout << yes;
  }
  if (a == 84) {
    ok = 1;
    cout << yes;
  }
  if (a == 85) {
    ok = 1;
    cout << yes;
  }
  if (a == 86) {
    ok = 1;
    cout << yes;
  }
  if (a == 88) {
    ok = 1;
    cout << yes;
  }
  if (ok == 0) {
  cout << no;
  }
  cout << endl;
  return 0;
}