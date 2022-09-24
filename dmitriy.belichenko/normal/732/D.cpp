#include<iostream>
#include<set>
#include<algorithm>
#include<math.h>
#include<string>
#include<vector>
#include<utility>


using namespace std;

vector<int> d;
vector<int> a;
int m;

bool flag(int day) {
vector<int> last;

for (int i = 0; i < m; i++)
{
last.push_back(-1);
}
vector<int> need(day + 1);
for (int i = 0; i <= day; i++) {
if (d[i] != 0) {
if (last[d[i] - 1] >= 0) {
need[last[d[i] - 1]] -= 1 + a[d[i] - 1];
}
last[d[i] - 1] = i;
need[i] += 1 + a[d[i] - 1];
}
}
if (need[0] > 1) {
return false;
}
for (int i = 1; i <= day; i++) {
need[i] += need[i - 1];
if (need[i] > i + 1) {
return false;
}
}
for (int i = 0; i < m; i++) {
if (last[i] == -1) {
return false;
}
}
return true;
}

int main()
{

 int n;
 int day;
 cin >> n >> m;
for (int i = 0; i < n; i++) {
cin >> day;
d.push_back(day);
}
 for (int i = 0; i < m; i++) {
 cin>> day;
 a.push_back(day);
}

if (!flag(n - 1)) {
cout << -1;
return 0;
}

 int left = 0, right = n;
  while (right - left > 1) {
   int mid = (left + right) / 2;
   if (flag(mid))
   {
   right = mid;
   }
   else 
   {
    left = mid;
   }
   }
cout<< right + 1;
return 0;
}