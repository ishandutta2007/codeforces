#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef pair<int,int> pii;

map<string,int> cnt;
map<string,set<string> > sub;
char inp[200],s[200];
int tmt,i,j,ans_1,ans_2;

int main(){
	while(gets(inp)){
		for(tmt=3;inp[tmt]!='\\';tmt++);
		for(j=0;j<tmt;j++) s[j]=inp[j];
		s[tmt]=0;
		cnt[s]++;
		for(i=strlen(inp)-1;i>tmt;i--)
			if(inp[i]=='\\'){
				inp[i]=0;
				sub[s].insert(inp);
			}
	}
	for(map<string,set<string> >::iterator it=sub.begin();it!=sub.end();it++)
		ans_1=max(ans_1,(int)((it->second).size()));
	for(map<string,int>::iterator it=cnt.begin();it!=cnt.end();it++)
		ans_2=max(ans_2,it->second);
	cout<<ans_1<<' '<<ans_2<<endl;
	return 0;
}