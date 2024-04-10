#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string s,a;

int D[101010],i,j,rec=-1,sum;

int main()
{
	cin>>s>>a;
	
	if(s.size()<a.size()){
		printf("0\n");
		return 0;
	}
	
	for(i=0;i<=s.size()-a.size();i++){
		for(j=0;j<a.size();j++){
			if(s[i+j]!=a[j]) break;
		}
		if(j==a.size()) D[i]=1;
	}
		
	for(i=0;i<s.size();){
		while(i<s.size() && !(D[i]==1 && !(i<=rec&&rec<i+a.size()))) i++;
		if(i>=s.size()) break;
		rec = i+a.size()-1; sum++;
	}
	
	printf("%d\n",sum);
	
	return 0;
}