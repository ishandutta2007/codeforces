#include <cstdio>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
vector<string>v[2];
bool input(string &inp){
	inp="";
	while(true){
		char in=getchar();
		if(in==';'||in==',')return true;
		if(in=='\n')return false;
		inp=inp+in;
	}
}
bool digit(string n){
	int len=n.length();
	if(len==0||(len>1&&n[0]=='0'))return false;
	for(int k=0;k<len;k++)
	if(!isdigit(n[k]))return false;
	return true;
}
void solve(){
	string now;
	while(input(now))
	v[digit(now)].push_back(now);
	v[digit(now)].push_back(now);
}
void print(int p){
	if(v[p].size()==0)putchar('-');
	else{
		printf("\"%s",v[p][0].c_str());
		for(int k=1;k<v[p].size();k++)
		printf(",%s",v[p][k].c_str());
		putchar('"');
	}
	putchar('\n');
}
int main(){
	solve();
	print(1);
	print(0);
	return 0;
}