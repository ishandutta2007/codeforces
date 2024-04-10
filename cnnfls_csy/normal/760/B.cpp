#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
using namespace std;
double aaaa,bbbb;
long long n,m,k,beg,mid,sum,end1;
int main()
{
   cin>>n>>m>>k;
   end1=(m-n);
   while(end1>=beg)
   {
   	  sum=0;
      mid=(beg+end1)/2;
      if(mid+1-k>0)
	  sum+=((k-1)*(2*mid-k))/2;
      else
      sum+=(mid*(mid-1))/2;
      if(mid+k-n>0)
      sum+=((n-k+1)*(2*mid+k-n))/2;
      else
      sum+=(mid*(mid+1))/2;
      if(sum>m-n)
      end1=mid-1;
      else if(sum<m-n)
      beg=mid+1;
      else if(sum==m-n)
      {cout<<mid+1;return 0;}
   }
   cout<<end1+1;
   return 0;
}