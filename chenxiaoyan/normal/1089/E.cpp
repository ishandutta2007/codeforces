#include<iostream>
using namespace std;
const string way[]=
{
	"a2","a3","a4","a5","a6","a7",
	"b7","b6","b5","b4","b3","b2","b1",
	"c1","c2","c3","c4","c5","c6","c7",
	"d7","d6","d5","d4","d3","d2","d1",
	"e1","e2","e3","e4","e5","e6","e7",
	"f7","f6","f5","f4","f3","f2","f1",
	"g1","g2","g3","g4","g5","g6",
	"h6","h5","h4","h3","h2","h1","h7",
	"g7",
	"g8","f8","e8","d8","c8","b8","a8"
};
int main()
{
	int n,i;
	cin>>n;
	cout<<"a1 ";
	if(n==2)
		cout<<"a8 h8";
	else if(n<=49)
	{
		n-=2;
		for(i=0;i<n;i++)
			cout<<way[i]<<" ";
		cout<<way[n-1][0]<<"8 h8";
	}
	else if(n==56)
		cout<<"a2 a3 a4 a5 a6 a7 "
		"b7 b6 b5 b4 b3 b2 b1 "
		"c1 c2 c3 c4 c5 c6 c7 "
		"d7 d6 d5 d4 d3 d2 d1 "
		"e1 e2 e3 e4 e5 e6 e7 "
		"f7 f6 f5 f4 f3 f2 f1 "
		"g1 g2 g3 g4 g5 g6 g7 "
		"h7 h6 h5 h4 h3 h2 h1 h8";
	else if(n==57)
		cout<<"a2 a3 a4 a5 a6 a7 "
		"b7 b6 b5 b4 b3 b2 b1 "
		"c1 c2 c3 c4 c5 c6 c7 "
		"d7 d6 d5 d4 d3 d2 d1 "
		"e1 e2 e3 e4 e5 e6 e7 "
		"f7 f6 f5 f4 f3 f2 f1 "
		"g1 g2 g3 g4 g5 g6 "
		"h6 h5 h4 h3 h2 h1 h7 "
		"g7 g8 "
		"h8";
	else
	{
		n-=1;
		for(i=0;i<n;i++)
			cout<<way[i]<<" ";
		cout<<"h8";
	}
	return 0;
}
/*1
4
*/