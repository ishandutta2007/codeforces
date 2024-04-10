#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<string>
using namespace std;
int a,b,c,d;   
int main()
{
    cin>>a>>b>>c>>d;
    for(int i=1; i<1000000; i++)
      {
	    if(i>=b && i>=d && i%c==d%c && i%a==b%a )
	    {
	      cout<<i<<"\n"; exit(0);
    	}
      }
    cout<<-1<<"\n";
    
}