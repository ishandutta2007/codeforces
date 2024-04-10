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
const int Maxk=1005;
string mul(string a,string b){
	int res[Maxk];
	memset(res,0,sizeof(res));
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for (int i=0;i<a.length();i++){
		for (int j=0;j<b.length();j++){
			res[i+j]+=(a[i]-'0')*(b[j]-'0');
		}
	}
	for (int i=0;i<Maxk;i++){
		if (res[i]>=10) {
			res[i+1]+=(res[i]/10);
			res[i]%=10;
		}
	}
	string ret;
	bool flag=false;
	for (int i=Maxk-1;i>=0;i--){
		if (flag || res[i]){
			flag=true;
			ret=ret+(char)(res[i]+'0');
		}
	}
	if (ret=="") ret="0";
	return ret;
}
string add(string a,string b){
	if (a.length()<b.length()) swap(a,b);
	while (a.length()!=b.length()){
		b='0'+b;
	}
	for (int i=a.length()-1;i>=0;i--){
		a[i]+=(b[i]-'0');
		if (a[i]>'9' && i){
			a[i]-=10;
			a[i-1]++;
		}
	}
	if (a[0]>'9'){
		a[0]-=10;
		a='1'+a;
	}
	return a;
}
const int Maxn=105;
int v[Maxn][Maxn];
int tmp[Maxn][Maxn];
int n,m;
bool flag;
int ansc[Maxn],ansr[Maxn];
int resc[Maxn],resr[Maxn];
int totsum,bestsum;
bool usec[Maxn][Maxn],user[Maxn][Maxn];
void Delc(int x,int val){
//	cout<<"DELc"<<' '<<x<<' '<<val<<endl;
	for (int i=0;i<m;i++){
		v[x][i]-=val;
		if (v[x][i]<0) flag=false;
	}/*
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++) cout<<v[i][j]<<' ';
		cout<<endl;
	}*/
}
void Addc(int x,int val){
	for (int i=0;i<m;i++){
		v[x][i]+=val;
		//if (v[x][i]==0) flag=false;
	}
}
void Delr(int x,int val){
//	cout<<"DELr"<<' '<<x<<' '<<val<<endl;
	for (int i=0;i<n;i++){
		v[i][x]-=val;
		if (v[i][x]<0) flag=false;
	}
	/*
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++) cout<<v[i][j]<<' ';
		cout<<endl;
	}*/
}
void Addr(int x,int val){
	for (int i=0;i<n;i++){
		v[i][x]+=val;
		//if (v[x][i]==0) flag=false;
	}
}
bool check(){
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++) if (v[i][j]!=0) return false;
	}
	return true;
}
void Search(){
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			if (usec[i][j] && !user[i][j]){
				int ttm=v[i][j];
				Delr(j,v[i][j]);
				if (!flag) return;
			//	user[i][j]=true;
				for (int ii=0;ii<n;ii++) user[ii][j]=true;
				ansr[j]+=ttm;totsum+=ttm;
				Search();
				//if (!check()) flag=false;
				return;
			}
			else if (!usec[i][j] && user[i][j]){
				int ttm=v[i][j];
				Delc(i,v[i][j]);
				if (!flag) return;
				for (int ii=0;ii<m;ii++) usec[i][ii]=true;
				ansc[i]+=ttm;
				totsum+=ttm;
			//	usec[i][j]=true;
				Search();
				//if (!check()) flag=false;
				return;
			}
		}
	}
}
int main(){

	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			scanf("%d",&v[i][j]);
			tmp[i][j]=v[i][j];
		}
	}bestsum=1e8;
//	cout<<v[0][0]<<endl;
	for (int i=0;i<=v[0][0];i++){
		
		memset(usec,0,sizeof(usec));
		memset(user,0,sizeof(user));
		memset(ansc,0,sizeof(ansc));
		memset(ansr,0,sizeof(ansr));
		totsum=i;
		ansc[0]=i;
		flag=true;
		Delc(0,i);
		if (!flag) continue;
		for (int j=0;j<m;j++){
			usec[0][j]=true;
		}
		Search();
		if (flag){
			if (check()){
				if (totsum<bestsum){
					bestsum=totsum;
					for (int j=0;j<n;j++) resc[j]=ansc[j];
					for (int j=0;j<m;j++) resr[j]=ansr[j];
				//	cout<<"Fuck"<<i<<endl;
				}
			}
			
		}
		for (int j=0;j<n;j++){
			for (int k=0;k<m;k++){
				v[j][k]=tmp[j][k];
			}
		}
		//cout<<endl;
	}
//	cout<<bestsum<<endl;
//	cout<<v[0][0]<<endl;
	if (bestsum>1000000){
		printf("-1\n");
	}
	else{
		printf("%d\n",bestsum);
		for (int i=0;i<n;i++){
			for (int j=0;j<resc[i];j++){
				printf("row %d\n",i+1);
			}
		}
		for (int i=0;i<m;i++){
			for (int j=0;j<resr[i];j++){
				printf("col %d\n",i+1);
			}
		}
	}
	return 0;
}