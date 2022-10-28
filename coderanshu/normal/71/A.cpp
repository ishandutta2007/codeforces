#include<bits/stdc++.h>
using namespace std;
int main()
{
   string s;
   int t;
   cin>>t;
   for(int i=0;i<t;i++)
   {
   cin>>s;
   if(s.length()>10)
   cout<<s[0]<<s.length()-2<<s[s.length()-1]<<"\n";
   else
   cout<<s<<"\n";
   }
   return 0; 
}