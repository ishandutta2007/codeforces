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
const int Maxn=100005;
struct node{
	node *l;
	node *r;
	int siz;
	node(){
		l=NULL;
		r=NULL;
		siz=0;
	}
};
node root;
void Add(int val){
	node *now=&root;
	now->siz++;
	for (int i=30;i>=0;i--){
		
		bool f=(val & (1<<i));
		if (!f){
			if (now->l==NULL) now->l=new node;
			now=now->l;
			//cout<<'l';
		}
		else {
			if (now->r==NULL) now->r=new node;
			now=now->r;
		}
		now->siz++;
		//if (now==NULL) now=new node;
	}
}
void Del(int val){
	node *now=&root;
	now->siz--;
	for (int i=30;i>=0;i--){
		
		bool f=(val & (1<<i));
		if (!f){
			now=now->l;
		}
		else {
			now=now->r;
		}now->siz--;
	}
}
int query(int val,int bound){
	node *now=&root;
	int ans=0;
	for (int i=30;i>=0;i--){
		if (now==NULL) break;
		bool nowbit=val & (1<<i);
		bool expbit=bound & (1<<i);
	//	cout<<nowbit<<expbit<<endl;
		if (expbit){
			if (nowbit){
				if (now->r!=NULL){
					ans+=now->r->siz;
			//		cout<<"suc";
				}
				if (now->l!=NULL)now=now->l; else break;
			}
			else{
				if (now->l!=NULL){
					ans+=now->l->siz;
				//	cout<<"suc";
				}
				if (now->r!=NULL)now=now->r; else break;
			}
		}
		else{
			if (nowbit){
				if (now->r!=NULL)now=now->r; else break;
			}
			else{
				if (now->l!=NULL)now=now->l; else break;
			}
		}
	}
	return ans;
}
int main(){
//	cout<<"good";
	int q;
	scanf("%d",&q);
	while(q--){
		int tp;
		scanf("%d",&tp);
		if (tp==1){
			int val;
			scanf("%d",&val);
			Add(val);
		}
		else if (tp==2){
			int val;
			scanf("%d",&val);
			Del(val);
		}
		else{
			int p,v;
			scanf("%d %d",&p,&v);
			printf("%d\n",query(p,v));
		}
	//	cout<<root.siz<<endl; 
	}
	return 0;
}