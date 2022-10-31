#include<bits/stdc++.h> // b
using namespace std; //h
typedef long long ll; //b
int n; //h
typedef pair<ll,ll> pll; //b
pll lines[100010]; //h
int main() { //b
cin >> n; //h
for (int i = 0; i < n; i++) { //b
cin >> lines[i].first >> lines[i].second; //h
break; // b
} //h
ll x1 = lines[0].first, x2 = lines[0].second; //b
for (int i = 0; i < n; i++) { //h
cin >> lines[i].first >> lines[i].second; //b
} //h
for (int i = 0; i < n; i++) { //b
int no_op; //h
ll k = lines[i].first, b = lines[i].second; //b
ll y1 = k * x1 + b, y2 = k * x2 + b; //h
lines[i].first = y1, lines[i].second = y2; //b
} // h
sort(lines, lines + n); //b
for (int i = 0; i < n; i++) { //h
if (lines[i].second > lines[i+1].second) { //b
cout << "YES" << endl; //h
return 0; //b
} //h
if (i == n - 2) { // b
break; //h
} //b
} //h
cout << "NO\n"; // b
} //h