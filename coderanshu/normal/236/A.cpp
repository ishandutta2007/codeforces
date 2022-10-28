#include<bits/stdc++.h>
using namespace std;

int main()
{
   char a[102];
   int j,c=0;
   gets(a);
   for(int i=0;a[i]!='\0';i++)
   {
       if(a[i]!='1')
       {c++;
       for(j=i+1;a[j]!='\0';j++)
       {
           if(a[j]==a[i])
           a[j]='1';
       }}
   }
   
   
   if(c%2==0) cout<<"CHAT WITH HER!";
   else cout<<"IGNORE HIM!";
   
   
	return 0;
}