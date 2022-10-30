#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxn=100005;
const int Maxk=27;
int nxt[Maxn][Maxk];
int pre[Maxn][Maxk];
vector<int> d1,d2;
int main(){
	string a,b;
	cin>>a;
	cin>>b;
	for (int i=0;i<26;i++){
		nxt[a.length()][i]=-1;
	}
	for (int i=a.length()-1;i>=0;i--){
		for (int j=0;j<26;j++){
			nxt[i][j]=nxt[i+1][j];
		}
		nxt[i][a[i]-'a']=i;
	}
	for (int i=0;i<a.length();i++){
		if (!i){
			for (int j=0;j<26;j++){
				pre[i][j]=-1;
			}
		}
		else{
			for (int j=0;j<26;j++){
				pre[i][j]=pre[i-1][j];
			}
		}
		pre[i][a[i]-'a']=i;
	//	cout<<i<<a[i]<<endl;
	}
//	cout<<"good"<<endl;
	int nowp=0;
	int p1,p2;
	for (int i=0;i<b.length();i++){
	if (nowp>=(int)a.length()) break;
		nowp=nxt[nowp][b[i]-'a']+1;
	//	cout<<nowp<<endl;
		
		if (nowp==0) break; else d1.push_back(nowp-1);
	}
	//cout<<endl;
	nowp=a.length()-1;
	for (int i=b.length()-1;i>=0;i--){
		if (nowp<0) break;
		nowp=pre[nowp][b[i]-'a']-1;
		
		if (nowp==-2)  break; else d2.push_back(nowp+1);
	}
	p1=0;
	p2=d2.size()-1;
	/*
	cout<<p1<<p2<<endl;
	for (int i=0;i<d1.size();i++){
		cout<<d1[i]<<endl;
	}
	cout<<endl;
	for (int i=0;i<d2.size();i++){
		cout<<d2[i]<<endl;
}
	cout<<endl;*/
	if (p2==(int)b.length()-1){
		printf("%s\n",b.c_str());
		return 0;
	}
	int Max=0,s1=-1,s2=-1;
	for (;p2>=-1;p2--){
		if (p1==-1) p1++;
		while (p1<d1.size() && d1[p1]<((p2==-1)?INF:d2[p2])){
			p1++;
		}
		p1--;
		if (p1<-1) p1=-1;
		if (Max<p1+p2+2){
			Max=p1+p2+2;
			s1=p1,s2=p2;
		}//cout<<p1<<' '<<p2<<' '<<Max<<endl;
	}
	//cout<<Max<<' '<<s1<<' '<<s2<<endl;
	if (s1==-1 && s2==-1){
		printf("-\n");
		return 0;
	}
	string ans;
	if (s1==-1){
		ans=b.substr(b.size()-s2-1);
	}
	else if (s2==-1){
		ans=b.substr(0,s1+1);
	}
	else
	ans=b.substr(0,s1+1)+b.substr(b.size()-s2-1);
	printf("%s\n",ans.c_str());
	return 0;
}
/*
aaaavvvvvvvvvvvvvvvv
vvvvvvvvvvvaaaaaa
*/