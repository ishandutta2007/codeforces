#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
main()
{
	ifstream in("input.txt");
	int a, b, err=0;
	cin>>a>>b;
	vector <int> ans;
	ans.push_back(b);
	while(b>a)
	{
		if(b%2==0) b=b/2;
		else if(b%10==1) b=b/10;
		else
		{
			err=1;
			break;
		}
		ans.push_back(b);
	}
	if(err) cout<<"NO";
	else
	{
		if(b==a)
		{
			cout<<"YES"<<"\n"<<ans.size()<<"\n";
			for(int a=ans.size()-1; a>=0; a--) cout<<ans[a]<<" ";
		}
		else cout<<"NO";
	}
}