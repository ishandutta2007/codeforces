#include <cstdio>
#include <vector>
#include <algorithm>

int main () {
   int n;
   scanf("%d", &n);
   std::vector<int> v;
   for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      v.push_back(x);
   }
   std::sort(v.begin(), v.end());
   int wynik = 1;
   for (int i = 0; i < v.size(); ++i) {
      if (wynik < v[i]) {
         printf("%d\n",wynik);
         return 0;
      }
      if (wynik == v[i]) ++wynik;
   }
       printf("%d\n",wynik);
         return 0;
     
}