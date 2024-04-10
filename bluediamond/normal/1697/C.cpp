/// 472 -> 473
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
///typedef long double ld;


signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE


  int Tests;
  cin >> Tests;

  for (int testCase = 1; testCase <= Tests; testCase++) {
    int n;
    string S, T;
    cin >> n >> S >> T;
    assert(n == (int) S.size());
    assert(n == (int) T.size());
    bool isGood = true;
    {
      vector<int> balance(3, 0);
      for (int i = 0; i < n; i++) {
        balance[S[i] - 'a']++;
        balance[T[i] - 'a']--;
      }
      isGood &= (*min_element(balance.begin(), balance.end()) == 0);
    }
    if (!isGood) {
      cout << "NO\n";
      continue;
    }
    {
      int cntS = 0, cntT = 0;
      vector<int> dataS, dataT;
      for (int i = 0; i < n; i++) {
        cntS += (S[i] == 'a');
        cntT += (T[i] == 'a');
        if (S[i] == 'b') {
          dataS.push_back(cntS);
        }
        if (T[i] == 'b') {
          dataT.push_back(cntT);
        }
      }
      int dim = (int) dataS.size();
      assert((int) dataS.size() == dim);
      assert((int) dataT.size() == dim);
      for (int i = 0; i < dim; i++) {
        isGood &= (dataS[i] >= dataT[i]);
      }
    }
    {
      int cntS = 0, cntT = 0;
      vector<int> dataS, dataT;
      for (int i = 0; i < n; i++) {
        cntS += (S[i] == 'a');
        cntT += (T[i] == 'a');
        if (S[i] == 'c') {
          dataS.push_back(cntS);
        }
        if (T[i] == 'c') {
          dataT.push_back(cntT);
        }
      }
      int dim = (int) dataS.size();
      assert((int) dataS.size() == dim);
      assert((int) dataT.size() == dim);
      for (int i = 0; i < dim; i++) {
        isGood &= (dataS[i] == dataT[i]);
      }
    }
    {
      int cntS = 0, cntT = 0;
      vector<int> dataS, dataT;
      for (int i = 0; i < n; i++) {
        cntS += (S[i] == 'c');
        cntT += (T[i] == 'c');
        if (S[i] == 'b') {
          dataS.push_back(cntS);
        }
        if (T[i] == 'b') {
          dataT.push_back(cntT);
        }
      }
      int dim = (int) dataS.size();
      assert((int) dataS.size() == dim);
      assert((int) dataT.size() == dim);
      for (int i = 0; i < dim; i++) {
        isGood &= (dataS[i] <= dataT[i]);
      }
    }
    cout << ((isGood) ? ("YES") : ("NO")) << "\n";
  }

}