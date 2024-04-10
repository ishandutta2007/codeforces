#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int K[55];
string c;

string name(int p)
{
	string s="";
	if(p<26){
		s += (p+'A');
		return s;
	}
	else{
		s += 'K';
		s += (p-26+'a');
		return s;
	}
}

int main()
{
	int n,k,i;
	scanf("%d%d",&n,&k);

	for(i=0;i<k-1;i++) K[i] = i, cout<<name(i)<<" ";
	for(;i<n;i++){
		cin>>c;
		if(c == "NO") K[i] = K[i-k+1], cout<<name(K[i])<<" ";
		else K[i] = i, cout<<name(i)<<" ";
	}

	cout<<endl;

	return 0;
}