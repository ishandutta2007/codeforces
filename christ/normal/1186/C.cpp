#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int psa[1000001];
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s1,s2;
    cin >> s1 >> s2;
    int curans = 0,res=0;
    for (int i = 1; i < s1.length(); i++) {
      psa[i] = psa[i-1] + (s1[i] != s1[i-1]);
    }
    for (int i = 0; i < s2.length(); i++) {
      curans += (s2[i] != s1[i]);
    }
    if (curans % 2 == 0) res++;
    for (int i = 1; i <= s1.length()-s2.length(); i++) {
      curans += psa[i+s2.length()-1] - psa[i-1];
      if (curans % 2 == 0) res++;
    }
    printf ("%d\n",res);
    return 0;
}