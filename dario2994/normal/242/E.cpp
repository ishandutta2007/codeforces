#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXC 21
#define MAXN (1<<17)
#define INF 1<< 30
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

typedef long long var;
class binTree{
	private:
		var operation(var x,var y){
			return x+y;
		}
		var * value;
		bool * flag;
		int length;
		
		
		void init1(int a,int b, int v){
			flag[v]=false;//TODO GENERALIZE1
			if(a==b)return;
			int m=(a+b)/2;
			init1(a,m,2*v);
			init1(m+1,b,2*v+1);
			value[v]=operation(value[2*v],value[2*v+1]);
		}
		
		void propagate(const int &a, const int &b, const int &v){
			if(!flag[v])return;//TODO GENERALIZE
			flag[v]=false;//TODO GENERALIZE1
			if(a==b)return;//foglia!
			int l=(b-a+1)/2;
			flag[2*v]=!flag[2*v];//TODO GENERALIZE
			flag[2*v+1]=!flag[2*v+1];//TODO GENERALIZE
			value[2*v]=l-value[2*v];//TODO GENERALIZE
			value[2*v+1]=l-value[2*v+1];//TODO GENERALIZE
		}
		
		LL get1(int a,int b,const int &l, const int &r, int v){
			propagate(a,b,v);
			if(b<l or r<a)return 0;
			else if(l<=a and b<=r)return value[v];
			int m=(a+b)/2;
			return operation(get1(a,m,l,r,2*v),get1(m+1,b,l,r,2*v+1));
		}
		
		void update1(int a,int b, const int &l, const int &r, int v){
			propagate(a,b,v);
			if(b<l or r<a)return;
			else if(l<=a and b<=r){
				value[v]=b-a+1-value[v];//TODO GENERALIZE
				flag[v]=!flag[v];//TODO GENERALIZE
				return;
			}
			int m=(a+b)/2;
			update1(a,m,l,r,2*v);
			update1(m+1,b,l,r,2*v+1);
			value[v]=operation(value[2*v],value[2*v+1]);
		}
	
	public:
		void init(int N,var * vv){
			length=1;
			while(length<N)length<<=1;
			value=new var[2*length];
			flag=new bool[2*length];
			for(int i=0;i<length;i++){
				if(i<N)value[i+length]=vv[i];
				else value[i+length]=0;
			}
			init1(0,length-1, 1);
		}
		
		LL get(int l, int r){
			return get1(0, length-1,l,r,1);
		}
		
		void update(int l, int r){
			update1(0, length-1,l,r,1);
		}
};

binTree tree[MAXC];

int main(){
	int N;
	cin >> N;
	var * vv=new var[N];
	var * temp=new var[N];
	for(int i=0;i<N;i++)cin >> vv[i];
	LL pot=1;
	for(int i=0;i<MAXC;i++){
		for(int j=0;j<N;j++)temp[j]=(vv[j]&pot)?1:0;
		tree[i].init(N,temp);
		pot<<=1;
	}
	int M;
	cin >> M;
	vector <LL> res;
	for(int i=0;i<M;i++){
		int t;
		cin >> t;
		if(t==1){
			int l,r;
			cin >> l >> r;
			l--;r--;
			pot=1;
			LL temp=0;
			for(int i=0;i<MAXC;i++){
				//~ cout << i << " " << tree[i].get(l,r) << "\n";
				temp+=pot*tree[i].get(l,r);
				pot<<=1;
			}
			res.push_back(temp);
		}
		else if(t==2){
			int l,r,x;
			cin >> l >> r >> x;
			l--;r--;
			pot=1;
			for(int i=0;i<MAXC;i++){
				if(x&pot){
					//~ cout << i << "\n";
					tree[i].update(l,r);
				}
				pot<<=1;
			}
		}
	}
	for(int i=0;i<int(res.size());i++)cout << res[i] << "\n";
}

//~ 5
//~ 0 0 1 1 1
//~ 1
//~ 2 1 3 1
//~ 1 2 4