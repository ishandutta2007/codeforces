#include <iostream>
#include <stdint.h>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using std::cin; using std::cout; using std::cerr; using std::endl; using std::max; using std::max_element;

int main()
{
	std::string s; cin>>s;
	int k; cin>>k;
	
	int v[26];
	for (int i=0; i<26; i++)
		cin>>v[i];
	
	int V=(*max_element(v, v+26));
	
	int result=((2*s.size()+1+k)*k*V)/2;

	for (int i=0; i<int(s.size()); i++)
		result+=(i+1)*v[s[i]-'a'];
	
	cout<<result<<endl;
	
	return 0;
}