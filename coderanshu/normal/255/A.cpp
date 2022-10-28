#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,x,bi=0,ch=0,ba=0,i;
   cin>>n;
   for(i=0;i<n;i++)
   {
       cin>>x;
       if(i%3==0)
       ch+=x;
       else if(i%3==1)
       bi+=x;
       else
       ba+=x;
   }
   (ba>ch)?(ba>bi)?cout<<"back":cout<<"biceps":(ch>bi)?cout<<"chest":cout<<"biceps";
    return 0; 
}