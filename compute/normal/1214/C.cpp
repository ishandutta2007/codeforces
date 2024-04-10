#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  string s;
  cin>>n>>s;
  int cur=0,l=0,r=0;
  int mi=0;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='(') cur++,l++;
    else cur--,r++;
    mi=min(mi,cur); 
  } 
  if(l!=r) cout<<"No"<<endl;
  else{
    if(mi>=-1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
  
}