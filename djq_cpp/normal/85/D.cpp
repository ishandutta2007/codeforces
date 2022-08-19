#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
struct node{
	node *son[2];
	int cnt;
	ll data[5];
	node(int dat=0){
		son[0]=son[1]=NULL; 
		data[0]=dat;
		data[1]=data[2]=data[3]=data[4]=0;
		cnt=1;
	}
};
int getsz(node* v){
	return v==NULL?0:v->cnt;
}
void UNION(node* v,node* s1,node* s2){
	rep(k,5)v->data[k]=0LL;
	if(s1!=NULL)rep(k,5)v->data[k]+=s1->data[k];
	if(s2!=NULL)rep(k,5)v->data[(k+getsz(s1))%5]+=s2->data[k];
}
void insert(node*& v,int cur,int mbit){
	if(v==NULL)v=new node();
	else v->cnt++;
	if(mbit<0)v->data[0]=cur;
	else{
		insert(v->son[cur>>mbit&1],cur,mbit-1);
		UNION(v,v->son[0],v->son[1]);
	}
}
void erase(node*& v,int cur,int mbit){
	v->cnt--;
	if(mbit>=0)erase(v->son[cur>>mbit&1],cur,mbit-1);
	if(v->cnt==0){
		delete v;
		v=NULL;
	}else UNION(v,v->son[0],v->son[1]);
}
node* root=new node();
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q,v;
	string S;
	cin>>q;
	rep(k,q){
		cin>>S;
		if(S=="sum")cout<<root->data[2]<<'\n';
		else{
			cin>>v;
			if(S=="add")insert(root,v,30);
			if(S=="del")erase(root,v,30);
		}
	}
	return 0;
}