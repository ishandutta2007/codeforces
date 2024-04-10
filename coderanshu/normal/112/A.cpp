#include<bits/stdc++.h>
using namespace std;

int main()
{
  char a[102],b[102];
  gets(a);
  gets(b);
  int flag=0,i;
  for(i=0;i<strlen(a);i++)
  {
      if(tolower(a[i])<tolower(b[i]))
      {
      flag=-1; break;
      }
      else if(tolower(a[i])>tolower(b[i]))
      {
          flag=1; break;
      }
  }
  cout<<flag;
	return 0;
}