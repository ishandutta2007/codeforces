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
struct node{
	int siz;
	node *l,*r;
	int ocr[33];
	vector<int> ha;
	node(){
		l=NULL;
		r=NULL;
		siz=0LL;
		for (int i=0;i<=30;i++) ocr[i]=0LL;
	}
}root;
const int Maxn=50005;
const long long mod=1000000007;
int a[Maxn];
LL final;
LL fuckyou;
int n;
long long m;
void add_occ(int val,node *&x){
	for (int i=30;i>=0;i--){
		if (val & (1<<i)){
			x->ocr[i]++;
		}
	}
	x->ha.push_back(val); 
}
void ADD(int val){
	node *now=&root;
	now->siz++;
	add_occ(val,now);
	for (int i=30;i>=0;i--){
		if (val & (1<<i)){
			if (now->r==NULL){
				now->r=new node;
			}
			now=now->r;
		}
		else{
			if (now->l==NULL){
				now->l=new node;
			}
			now=now->l;
		}
		now->siz++;
		add_occ(val,now);
	}
}
LL query(LL val,LL lim){
	//cout<<val<<' '<<lim<<endl;
	node *now=&root;
	LL res=0;
	LL nv=0;
	for (int i=30;i>=0;i--){
		LL nb=(1<<i);
		if (val & (1<<i)){
			if (nv+nb>=lim){
			//	cout<<'r';
				if (now->l!=NULL){
					res+=now->l->siz;
				}
				if (now->r==NULL){
					break;
				}
				now=now->r;
			}
			else{
				if (now->l==NULL){
					break;
				}
				now=now->l;
				nv+=nb;
				//cout<<'l';
			}
		}
		else{
			if (nv+nb>=lim){//cout<<'l';
				if (now->r!=NULL){
					res+=now->r->siz;
				}
				if (now->l==NULL){
					break;
				}
				now=now->l;
			}
			else{
				//cout<<'r';
				if (now->r==NULL){
					break;
				}
				now=now->r;
				nv+=nb;
			}
		}
	}
	return res;
}
long long query2(int val,int lim){
	//cout<<val<<' '<<lim<<endl;
	node *now=&root;
	long long res=0LL;
	LL nv=0LL;
	for (int i=30;i>=0;i--){
		LL nb=(1<<i);
		if (val & (1<<i)){
			if (nv+nb>=lim){
			//	cout<<'r';
				if (now->l!=NULL){
					if (now->l->siz>=30){
						LL sizz=now->l->siz;
						int tj=1;
						for (int j=0;j<=30;j++){
							//tj=(1<<j);
							if (val & tj){
								res+=(LL)tj*(sizz-now->l->ocr[j]);
							}
							else{
								res+=(LL)tj*now->l->ocr[j];
							}
							tj<<=1;
						}
					}
					else{
						for (int j=0;j<now->l->ha.size();j++){
							res+=(LL)val^now->l->ha[j];
						}
					}
				}
				if (now->r==NULL){
					break;
				}
				now=now->r;
			}
			else{
				if (now->l==NULL){
					break;
				}
				now=now->l;
				nv+=nb;
			}
		}
		else{
			if (nv+nb>=(LL)lim){
				if (now->r!=NULL){
					if (now->r->siz>=30){
					LL sizz=now->r->siz;
					LL tj=1;
					for (int j=0;j<=30;j++){
						if (val & tj){
							res+=tj*(LL)(sizz-now->r->ocr[j]);
						}
						else{
							res+=tj*(LL)now->r->ocr[j];
						}
						tj<<=1;
					}	
					}
					else{
						for (int j=0;j<now->r->ha.size();j++){
							res+=(LL)val^now->r->ha[j];
						}
					}
				}
				if (now->l==NULL){
					break;
				}
				now=now->l;
			}
			else{
				//cout<<'r';
				if (now->r==NULL){
					break;
				}
				now=now->r;
				nv+=nb;
			}
		}
		
	}
	return res;
}
bool check(LL lim){
	long long tot=0;
	for (int i=0;i<n;i++){
		tot+=query((LL)a[i],lim);
	//	cout<<endl;
	}
//	cout<<tot/2<<endl;
	tot/=2;
	fuckyou=tot;
	return tot>=(LL)m;
}
void calc(int lim){
	final=0LL;
	for (int i=0;i<n;i++){
		long long nx=query2(a[i],lim);
		final+=nx;
	}
}
int main(){

	scanf("%d %I64d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		ADD(a[i]);
	}
	//cout<<root.siz<<endl;
	LL l=1,r=2147483647;
	while (l<r-1){
		long long tmp=(LL)l+r;
		tmp/=2;
		if (check(tmp)){
			l=tmp;
		}
		else{
			r=tmp;
		}
	}
	LL md=0;
	if (check(r)){
		md=r;
	}
	else{
		md=l;
	}
	check(md);
	LL fuckk=0LL;
	if (fuckyou>m){
		fuckk=(LL)md*(LL)(fuckyou-m);
	}
//	cout<<md<<endl;
//	return 0;
	calc(md);
	final/=2;
	final-=fuckk;
	printf("%I64d\n",final%mod);
	return 0;
} 
/*
3 1
1 2 3
*/