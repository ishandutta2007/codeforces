#include<bits/stdc++.h>
using namespace std;
int main()
{
   string s;
  cin>>s;
  for(int i=0;i<s.length();i++)
  {
      if(s[i]=='a'|| s[i]=='y' || s[i]=='Y' ||s[i]=='e'|| s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
        {
            s.erase(s.begin()+i);i--;
        }
        else
        {
            s[i]=tolower(s[i]);
            s.insert(i,".");i++;
        }
      
  } 
  cout<<s;
   return 0; 
}