#include<bits/stdc++.h>
using namespace std;
#define y1 y114514
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define M 1000000007
#define all(a) a.begin(), a.end()
typedef long long ll;

char str[100], first_s[100];
string s;

void ok(){
	cout << "normal" << endl;
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	exit(0);
}

void bad(){
	cout << "grumpy" << endl;
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	exit(0);
}

int main(){
	int cntno = 0;
	for(int i = 0; i < 10; ++i){
		cout << i << endl;
		gets(str);
		sscanf(str, "%s", first_s);
		s = first_s;
		if(s == "great") ok();
		else if(s == "don't"){
			if(str[6] == 'e') bad();
			else ok();
		}else if(s == "not") ok();
		else if(s == "cool") ok();
		else if(s == "worse") bad();
		else if(s == "terrible") bad();
		else if(s == "go") bad();
		else if(s == "are") bad();
		else if(s == "no"){
			if(str[2] == ' ') bad();
			else ++cntno;
		}
		if(cntno > 3) ok();
	}
	bad();
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}