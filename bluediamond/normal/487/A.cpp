#include <bits/stdc++.h>

using namespace std;

bool win(int hpY, int atkY, int defY, int hpM, int atkM, int defM)
{
  int scad1 = max(0, atkY - defM);
  int scad2 = max(0, atkM - defY);
  if (scad1 == 0) return (scad2 > 0);
  int x = hpM / scad1 + ((hpM % scad1) > 0);
  hpM -= scad1 * x;
  hpY -= scad2 * x;
  return (hpY > 0);
}

int main()
{
  int hpY, atkY, defY;
  int hpM, atkM, defM;

  cin >> hpY >> atkY >> defY;
  cin >> hpM >> atkM >> defM;
  int a, b, c;
  cin >> a >> b >> c;


  int best = (int) 1e9;

  for (int cntA = 0; cntA <= 1000; cntA++)
  {
    for (int cntB = 0; cntB <= 1000; cntB++)
    {
      int lo = 0, hi = 1000, ans = 10000;
      while (lo <= hi)
      {
        int mid = (lo + hi) / 2;
        if (win(hpY + cntA, atkY + cntB, defY + mid, hpM, atkM, defM))
        {
          ans = mid;
          hi = mid - 1;
        }
        else
          lo = mid + 1;
      }
      best = min(best, cntA * a + cntB * b + ans * c);
    }
  }
  cout << best << "\n";

  return 0;
}