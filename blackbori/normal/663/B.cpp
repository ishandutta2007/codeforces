#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef long long LL;

int f()
{
	string s;
	
	cin >> s;
	s.erase(0,4);
	
	if(s.size()==1){
		if(s < "9") cout << "199"+s << endl;
		else cout << "198"+s << endl;
	}
	if(s.size()==2){
		if(s < "99") cout << "20"+s << endl;
		else cout << "1999" << endl;
	}
	if(s.size()==3){
		if(s < "099") cout << "3"+s << endl;
		else cout << "2"+s << endl;
	}
	if(s.size()==4){
		if(s < "3099") cout << "1"+s << endl;
		else cout << s << endl;
	}
	if(s.size()==5){
		if(s < "13099") cout << "1"+s << endl;
		else cout << s << endl;
	}
	if(s.size()==6){
		if(s < "113099") cout << "1"+s << endl;
		else cout << s << endl;
	}
	if(s.size()==7){
		if(s < "1113099") cout << "1"+s << endl;
		else cout << s << endl;
	}
	if(s.size()==8){
		if(s < "11113099") cout << "1"+s << endl;
		else cout << s << endl;
	}
	if(s.size()==9){
		if(s < "111113099") cout << "1"+s << endl;
		else cout << s << endl;
	}
	
	return 0;
}

int main()
{
	cin.sync_with_stdio(false);
	
	int i,n;
	
	cin>>n;
	for(i=0;i<n;i++) f();
	
	return 0;
}