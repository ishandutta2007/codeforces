#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include  <queue>
#include <sstream>
#include <stack>
#include <time.h>
#include <vector>
#include <complex>
#include <map>
#include <set>
#include <iomanip>
#include <math.h>
#include <stdlib.h>
#include <list>
#include <utility>
#include <memory>
#include <cstring>
#include <fstream>
#include <numeric>
#include <assert.h>
#include <bits/stdc++.h>
using namespace std;
struct racer{
	int chap[53];
	int points;
};
int point_got[10]={25,18,15,12,10,8,6,4,2,1};
map <string,racer> mp;
bool ph(racer s1,racer s2){
	if (s1.points > s2.points) return true;
	if (s2.points > s1.points ) return false;
	for (int i=0;i<50;i++){
		if (s1.chap[i] > s2.chap[i]) return true;
		if (s2.chap[i] > s1.chap[i]) return false;
	}
}
bool ch(racer s1,racer s2){
	if (s1.chap[0] > s2.chap[0]) return true;
	if (s2.chap[0] > s1.chap[0]) return false;
	return ph(s1,s2);
}
int main(){
	string ans1,ans2;
	int races;
	cin>>races;
	while (races--){
		int m;
		cin>>m;
		for (int i=0;i<m;i++){
			string s;
			cin>>s;
			if (i<10) mp[s].points+=point_got[i];
			mp[s].chap[i]++;
		}
	}
	for (map<string,racer>::iterator it=mp.begin();it!=mp.end();it++){
		if (ph(it->second,mp[ans1])) ans1=it->first;
        if (ch(it->second,mp[ans2])) ans2=it->first;
    }
    cout<<ans1<<endl<<ans2;
    return 0;
}