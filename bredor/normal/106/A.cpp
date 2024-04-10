//  228

#include <bits/stdc++.h>
using namespace std;
char ar[] = {'6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
int main()
{
  string s2, s3;
  char s1;
  int i, pos = -1, pos2 = -1;
  cin >> s1;
  cin >> s2 >> s3;
  if (s2[1] == s1&&s3[1]!=s1)
    cout << "YES\n";
  else if (s2[1] != s3[1])
    cout << "NO\n";
  else
  {
    for (i = 0; i < 9; i++)
    {
      if (ar[i] == s2[0])
      {
        pos = i;
        break;
      }
    }
    
    for (i = 0; i < 9; i++)
    {
      if (ar[i] == s3[0])
      {
        pos2 = i;
        break;
      }
    }
    
    if (pos > pos2)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}