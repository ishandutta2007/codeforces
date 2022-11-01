#include <iostream>
using namespace std;
int main()
{
    int n,a,b,s=0; 
	cin>>n;
	for (int i=0;i<n;i++)
	  {
		 cin>>a>>b; 
	    	if (a>b) s++; 
		 else if (a<b) 	s--;
	 };
    if (s>0) 
	cout<<"Mishka"; 
	else if (s<0) 
	cout<<"Chris"; 
	else cout<<"Friendship is magic!^^";
	return 0;
}