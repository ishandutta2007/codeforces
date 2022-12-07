#include <iostream>
#include <string>
using namespace std;
int main()
{
	string st;
	bool f=0;
	cin>>st;
	for(int a=st.size()/2+1; a<st.size(); a++)
	{
		if(st.substr(0, a)==st.substr(st.size()-a, a))
		{
			cout<<"YES"<<"\n"<<st.substr(0, a);
			f=1;
			break;
		}
	}
	if(f==0) cout<<"NO";
}