#include<bits/stdc++.h>
using namespace std;
int main()
{
   string s ;
  cin>>s;
  int a[100],j,i;
  for(i=0,j=0;i<s.length();i+=2,j++)
  {
      
      a[j]=s[i]-48;
  }
  sort(a,a+j);
  cout<<a[0];
  for(i=1;i<j;i++)
  {
      cout<<"+"<<a[i];
  }
 
 
   return 0; 
}