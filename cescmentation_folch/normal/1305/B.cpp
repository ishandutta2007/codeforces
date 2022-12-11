        #include<bits/stdc++.h>
         
        using namespace std;
         
        typedef long long ll;
        typedef long double ld;
        typedef pair<int, int> pi;
        typedef vector<int> vi;
        typedef vector<vi> vvi;
        typedef vector<pi> vpi;
        typedef vector<vpi> vvpi;
         
        int main() {
          ios_base::sync_with_stdio(false);
          cin.tie(0);
          string s;
          cin >> s;
          int n = (int)s.size();
          vi V(n, 0);
          vvi R;
          while (1) {
            int ind1 = 0;
            int ind2 = n-1;
            vi D1;
            while (ind1 < ind2) {
              while (ind1 < n and (V[ind1] or s[ind1] == ')')) ++ind1;
              while (ind2 > 0 and (V[ind2] or s[ind2] == '(')) --ind2;
              if (ind1 < ind2) {
                V[ind1] = V[ind2] = 1;
                D1.push_back(ind1);
                D1.push_back(ind2);
                --ind2;
                ++ind1;
              }
              else break;
            }
            if (D1.size() == 0) break;
            sort(D1.begin(), D1.end());
            R.push_back(D1);
          }
          cout << R.size() << '\n';
          for (auto v : R) {
            cout << v.size() << '\n';
            for (int i = 0; i < (int)v.size(); ++i) {
              if (i) cout << ' ';
              cout << 1+v[i];
            }
            cout << '\n';
          }
        }