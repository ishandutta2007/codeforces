#include<bits/stdc++.h>
using namespace std;
string opt[60]={"a1","b1","c1","d1","e1","f1","g1","h1","h2","g2","f2","e2","d2","c2","b2","a2","a3","b3","c3","d3","e3","f3","g3","h3","h4","g4","f4","e4","d4","c4","b4","a4","a5","b5","c5","d5","e5","f5","g5","h5","h6","g6","f6","e6","d6","c6","b6","a6","a7","b7","c7","d7","e7","f7","g7","h7"};
string opend[]={"a7","a8","b8","b7","c7","c8","d8","d7","e7","e8","f8","f7","g7","g8"};
int main()
{
	int n;
	cin>>n;
	if(n-2>54)
	{
		for(int i=0;i<=47;i++)
			cout<<opt[i]<<' ';
		if(n!=63)
		{
			int ttt=n-2-48;
			for(int i=0;i<=ttt;i++)
				cout<<opend[i]<<' ';
			if(opend[ttt][1]=='7')
				cout<<"h7 h8\n";
			else cout<<"g8 h8\n";
		}
		else{
			for(int i=0;i<12;i++)
			{
				cout<<opend[i]<<' ';
			}
			cout<<"h7 g7 g8 h8\n";
		}
	}
	else{
		int ttt=n-2;
		for(int i=0;i<=ttt;i++)
		{
			cout<<opt[i]<<' ';
		}
		if(opt[ttt][0]=='h')
			cout<<"h7 h8\n";
		else{
			cout<<opt[ttt][0]<<"8 "<<"h8"<<endl;;
		}
	}
}