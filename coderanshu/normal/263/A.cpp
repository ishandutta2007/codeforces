#include<bits/stdc++.h>
using namespace std;

int main()
{
   int a[5][5],i,j,x,y;
   for(i=0;i<5;i++)
   {
       for(j=0;j<5;j++)
       {
       cin>>a[i][j];
       if(a[i][j]==1)
       {
           x=i;y=j;
       }
       }
   }
  
   i=((x-2>=0)?x-2:2-x) +((y-2>=0)?y-2:2-y);
   cout<<i;
   
   
	return 0;
}