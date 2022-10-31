#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	string ss;
	cin>>ss;
	for (int i=0;i<=ss.length()-1;i++)
	{
		char c=ss[i];
		if (c==65||c==69||c==73||c==79||c==85||c==89||c==97||c==101||c==105|c==111||c==117||c==121)
		;
		else
		{
			if(c<=90) 
			{
				int temp=c;
				temp+=32;
				c=temp;
			}
			cout<<"."<<c;
		}
	}
	return 0;	
}