#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
   ios_base::sync_with_stdio(0);
   string s;
   long int r=-1,l=-1,i;
   cin>>s;
   for(i=s.length()-2;i>=0;i--)
   {
       if(s[i]%2==0){r=i; break;}
   }
   for(i=0;i<s.length()-1;i++)
   {
       if(s[i]%2==0 && s[i]<s[s.length()-1])
       {
           l=i;break;
       }
   }
   if(l!=-1){swap (s[l],s[s.length()-1]);cout<<s;}
   else
   {
       if(r!=-1)
       {
           swap(s[r],s[s.length()-1]);
           cout<<s;
       }
       else cout<<-1;
   }
   
    return 0;
}