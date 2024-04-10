#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int k,a,b;
int main()
{
   cin>>k>>a>>b;
   string s;
   cin>>s;
   int len = s.length();
   //cout<<"len="<<len<<endl;
   if(b*k<len || a*k>len){
       cout<<"No solution"<<endl;
       exit(0);
   }
   int start=0;
   for(int i=k;i>=1;i--)
   {
	 for(int j=start;j<start+len/i;j++)
	 {
	    cout<<s[j];
	 }
			
	 start+=len/i;
 	 len=len-len/i;
	 cout<<endl;
   }
    return 0;
}