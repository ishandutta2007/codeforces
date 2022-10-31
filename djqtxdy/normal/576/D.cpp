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
#define INF 1500000000
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
const int Maxn=155;
int n;
int dist[Maxn][Maxn];
struct matrix{
	bitset<Maxn> a[Maxn];
	void _(int x){
		for (int i=0;i<Maxn;i++){
			for (int j=0;j<Maxn;j++) a[i][j]=0;
			a[i][i]=x;
		}
	}
	void debug(){
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				printf("%d ",(int)a[i][j]);
			}
			printf("\n");
		}
	}
};
matrix mult(matrix x,matrix y){
	matrix ans;
	ans._(0);
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (x.a[i][j]){
				ans.a[i]|=y.a[j];
			} 
		}
	}
	return ans;
}
matrix qp(matrix x,int p){
	if (p==0){
		matrix r;
		r._(1);
		return r;
	}
	if (p==1) return x;
	if (p%2==0){
		matrix y=qp(x,p/2);
		return mult(y,y);
	}
	else{
		matrix y=qp(x,p/2);
		return mult(mult(y,y),x);
	}
}
bool canr[Maxn],tmpp[Maxn];
int main(){
	int m;
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			dist[i][j]=INF;
		}
	}
	dist[n-1][n-1]=0;
	for (int i=0;i<m;i++){
		int u,v,d;
		scanf("%d %d %d",&u,&v,&d);
		u--,v--;
		dist[u][v]=min(dist[u][v],d);
	}
	vector<int> d;
	d.clear();
	for (int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			d.push_back(dist[i][j]);
		}
	} 
	d.push_back(INF);
	sort(d.begin(),d.end());
	d.resize(unique(d.begin(),d.end())-d.begin());
	if (d[0]!=0){
		printf("Impossible\n");
		return 0;
	}
	dist[n-1][n-1]=0;
	canr[0]=true;
	for (int i=0;i<d.size()-1;i++){
	//	cout<<d[i]<<endl;
		int pw=d[i+1]-d[i];
		matrix x,y;
		x._(0);
		for (int j=0;j<n;j++){
			for (int k=0;k<n;k++){
				x.a[j][k]=(dist[j][k]<=d[i]);
			}
		}
		y=x;
		x=qp(x,pw);
		//x.debug();
		bool flag=false;
		for (int j=0;j<n;j++){
			if (canr[j]){
				if (x.a[j][n-1]){
					flag=true;
				}
			}
		}
		if (!flag){
			memset(tmpp,false,sizeof(tmpp));
			for (int j=0;j<n;j++){
				if (canr[j]){
					for (int k=0;k<n;k++){
						tmpp[k]|=x.a[j][k];
					}
				}
			}
			for (int j=0;j<n;j++){
				canr[j]=tmpp[j];
			}
		}
		else{
			int l=0,r=pw;
			while (l<r-1){
				long long bmid=(LL)((LL)l+r)/2;
				int mid=(int)bmid;
				matrix tmp=qp(y,mid);
				bool f2=false;
				for (int j=0;j<n;j++){
					if (canr[j] && tmp.a[j][n-1]) f2=true;
				}
				if (f2) r=mid; else l=mid;
			}
			printf("%d\n",d[i]+r);
			return 0;
		}
	}
	printf("Impossible\n");
	return 0;
}