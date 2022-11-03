#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
   
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
  
typedef long long ll;

const int max_n = 1e5;

int n;

int is_prime[max_n + 1];
int used[max_n + 1];

vector<pair<int, int> > ans;
vector<int> p;

int main()
{
 //   freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    
    for (int i = 2; i <= max_n; ++i) is_prime[i] = true;
    for (int i = 2; i * i <= n; ++i)
        if (is_prime[i])
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
    for (int i = 3; 2 * i <= n; ++i)
        if (is_prime[i]) {
            p.clear();
            for (int j = i; j <= n; j += i)
                if (!used[j])
                    p.push_back(j);
            if ((p.size() & 1) == 1) {
                swap(p[1], p[p.size() - 1]);
            }
            for (int j = 0; j + 1 < (int) p.size(); j += 2) {
                ans.push_back(make_pair(p[j], p[j + 1]));
                used[p[j]] = used[p[j + 1]] = true;
            }
        }
    
    p.clear();
    for (int i = 2; i <= n; i += 2)
        if (!used[i]) {
            p.push_back(i);
        }
    for (int i = 0; i + 1 < (int) p.size(); i += 2)
        ans.push_back(make_pair(p[i], p[i + 1]));

    printf("%d\n", (int) ans.size());
    for (int i = 0; i < (int) ans.size(); ++i)
        printf("%d %d\n", ans[i].first, ans[i].second);
    
    
    return 0;
}