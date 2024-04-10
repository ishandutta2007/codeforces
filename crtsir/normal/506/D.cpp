#include<bits/stdc++.h>
using namespace std;
map<int,int>P[100003];
map<pair<int,int>,int>M;
int got(int x,int v){
	if(!P[x].count(v)||P[x][v]==v)return P[x][v]=v;
	else return P[x][v]=got(x,P[x][v]);
}
void add(int x,int a,int b){
	a=got(x,a);b=got(x,b);
	if(a!=b)P[x][b]=a;
}
vector<pair<int,int> >A[100003];
int n,m,a,b,c,q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&c),a--,b--,c--;
		add(c,a,b);
	}
	int cnt=0;
	for(int i=0;i<m;i++)
		for(map<int,int>::iterator it=P[i].begin();it!=P[i].end();it++)
			A[it->first].push_back(make_pair(i,it->second));
	for(int i=0;i<n;i++)
		for(int j=0;j<A[i].size();j++)
			A[i][j].second=got(A[i][j].first,i);
	scanf("%d",&q);
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);x--;y--;
		if(A[x].size()>A[y].size()||(A[x].size()==A[y].size()&&x>y))swap(x,y);
		if(M.count(make_pair(x,y)))
			printf("%d\n",M[make_pair(x,y)]);
		else{
			int res=0;
			for(int i=0;i<A[x].size();i++)
				if(binary_search(A[y].begin(),A[y].end(),A[x][i]))res++;
			M[make_pair(x,y)]=res;
			printf("%d\n",res);
		}
	}
}