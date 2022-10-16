//  228

#include<bits/stdc++.h>
#define ll long long
using namespace std;
 
 int main()
 {
   int n;
    cin>>n; 
    int sum=n-10;
    int ways=0;
    if(sum>=1&&sum<=9||(sum==11))
    ways+=4;
    else if(sum==10)
    ways+=4*3+3;
    else
    ways=0;
    cout<<ways;
    
  return 0;
 }