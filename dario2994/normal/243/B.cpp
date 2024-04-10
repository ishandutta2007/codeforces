#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAXN 100010
#define INF (1<<30)
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;

int N,M;
int h,t;
int deg[MAXN];
int primo[MAXN];
int secondo[MAXN];
vector <int> aa[MAXN];
bool head[MAXN];
bool tail[MAXN];
bool amiciT[MAXN];
bool amiciC[MAXN];

void unisci(vector <int> &u, vector <int> &v, vector <int> &res){
	int last=-1;
	int it2=0;
	int l1=u.size();
	int l2=v.size();
	for(int it1=0;it1<l1;it1++){
		while(it2<l2 and v[it2]<=u[it1] ){
			if(v[it2]!=last){
				res.push_back(v[it2]);
				last=v[it2];
				it2++;
			}
		}
		if(u[it1]==last)continue;
		res.push_back(u[it1]);
		last=u[it1];
	}
	for(;it2<l2;it2++){
		if(v[it2]!=last){
			res.push_back(v[it2]);
			last=v[it2];
		}
	}
}

int main(){
	//~ vector <int> A;
	//~ int bb;
	//~ cin >> bb;
	//~ for(int i=0;i<bb;i++){
		//~ int t;
		//~ cin >> t;
		//~ A.push_back(t);
	//~ }
	//~ vector <int> B;
	//~ cin >> bb;
	//~ for(int i=0;i<bb;i++){
		//~ int t;
		//~ cin >> t;
		//~ B.push_back(t);
	//~ }
	//~ vector <int> aaa;
	//~ unisci(A,B,aaa);
	//~ for(int i=0;i<aaa.size();i++)cout << aaa[i] << " ";
	cin >> N >> M >> h >> t;
	for(int i=0;i<M;i++){
		int x,y;
		cin >> x >> y;
		deg[x]++;
		deg[y]++;
		primo[i]=x;
		secondo[i]=y;
		aa[x].push_back(y);
		aa[y].push_back(x);
	}
	for(int i=1;i<=N;i++){
		if(deg[i]>=h+1)head[i]=true;
		if(deg[i]>=t+1)tail[i]=true;
	}
	for(int i=1;i<=N;i++){
		sort(aa[i].begin(),aa[i].end());
	}
	int s1=-1,s2=-1;
	for(int i=0;i<M;i++){
		int x=primo[i];
		int y=secondo[i];
		if((head[x] and tail[y]) or (tail[x] and head[y])){
			vector <int> unione;
			unisci(aa[x],aa[y],unione);
			if(int(unione.size())>=h+t+2){
				s1=x;
				s2=y;
				break;
			}
		}
	}
	
	if(s1==-1 and s2==-1){
		cout << "NO";
		return 0;
	}
	int testa,coda;
	if(head[s1] and tail[s2]){
		testa=s1;
		coda=s2;
	}
	else{
		testa=s2;
		coda=s1;
	}
	cout << "YES\n";
	cout << testa << " " << coda <<"\n";
	for(int i=0;i<int(aa[testa].size());i++){
		if(aa[testa][i]==coda)continue;
		amiciT[aa[testa][i]]=true;
	}
	for(int i=0;i<int(aa[coda].size());i++){
		if(aa[coda][i]==testa)continue;
		amiciC[aa[coda][i]]=true;
	}
	for(int i=1;i<=N;i++){
		if(h==0)break;
		if(amiciT[i] and !amiciC[i]){
			cout << i << " ";
			h--;
		}
	}
	for(int i=1;i<=N;i++){
		if(h==0)break;
		if(amiciT[i] and amiciC[i]){
			cout << i << " ";
			amiciC[i]=false;
			h--;
		}
	}
	cout << "\n";
	for(int i=1;i<=N;i++){
		if(t==0)break;
		if(amiciC[i]){
			cout << i << " ";
			t--;
		}
	}
}