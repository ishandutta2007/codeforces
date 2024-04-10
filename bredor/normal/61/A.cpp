//  228

#include<bits/stdc++.h>
using namespace std;

int main()
{
  char a[105],b[105],ans[105];
  cin >> a;
  cin >>  b;
  for(int i=0;i<strlen(a);i++)
  {
    if(a[i]!=b[i])
    ans[i]='1';
    else
    ans[i]='0';
  }
  for(int i=0;i<strlen(a);i++)
  {
    cout << ans[i];
  }
}