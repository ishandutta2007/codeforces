#include <iostream>
#include <algorithm>
#include <cmath>
#define INT long long

using namespace std;

#define MODE_LESS 0 
#define MODE_MORE_OR_EQUAL 3
#define MODE_MORE 1
#define MODE_LESS_OR_EQUAL 2

char parse_mode(char a, char b)
{
	char mode = (a=='>') ? MODE_MORE : MODE_LESS;
	if (b=='=') mode+=2;
	return mode;
}

int main()
{
	pair<INT, INT> Range;
	Range.first = -2LL*1000LL*1000LL*1000LL;
	Range.second = 2LL*1000LL*1000LL*1000LL;
	int questions; cin>>questions; cin.get();
	for (int i=0; i < questions; i++)
	{
		char a; char b; char c; long long NUM;
		a = cin.get(); b = cin.get();
		cin>>NUM; cin.get(); c=cin.get();
		
		char mode = parse_mode(a, b);
		if (c=='N') mode=3-mode;
		
		//cerr<<"DBG "<<(int)mode<<" "<<a<<" "<<b<<" "<<c<<" "<<NUM<<endl;
		
		if (mode==MODE_LESS)
			Range.second = min(Range.second, NUM-1);
		else if (mode==MODE_LESS_OR_EQUAL)
			Range.second = min(Range.second, NUM);
		else if (mode==MODE_MORE)
			Range.first = max(Range.first, NUM+1);
		else //mode == MODE_MORE_OR_EQUAL
			Range.first = max(Range.first, NUM);
		cin.get();
	}

	if (Range.first <= Range.second)
		cout<<Range.first<<"\n";
	else
		cout<<"Impossible\n";


	return 0;
}