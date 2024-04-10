#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,k;
vector <pair <int,int> >sight;
vector <char> nome;
int isola[1010][1010];
vector <pair <char,int> > istr;
int rig[1010][1010];
int col[1010][1010];
int u,v;

bool check(char dir, int len){
	if(dir=='N'){
		if(u-len<=0)return false;
		if(col[u-1][v]-col[u-len-1][v]<len)return false;
		u=u-len;
		return true;
	}
	if(dir=='S'){
		if(u+len>=n-1)return false;
		if(col[u+len][v]-col[u][v]<len)return false;
		u=u+len;
		return true;
	}
	if(dir=='W'){
		if(v-len<=0)return false;
		if(rig[u][v-1]-rig[u][v-len-1]<len)return false;
		v=v-len;
		return true;
	}
	if(dir=='E'){
		if(v+len>=m-1)return false;
		if(rig[u][v+len]-rig[u][v]<len)return false;
		v=v+len;
		return true;
	}
	return false;
}

bool prova(int x,int y){
	u=x;
	v=y;
	//cout << endl << u << " " << v << endl;
	for(int i=0;i<k;i++){
		//cout << i << " ";
		if(!check(istr[i].first,istr[i].second))return false;
	}
	return true;
}

int main(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char x;
			cin >> x;
			if('A'<=x and x<='Z'){
				nome.push_back(x);
				sight.push_back(make_pair(i,j));
			}
			if(x=='#')isola[i][j]=0;
			else isola[i][j]=1;
		}
	}
	cin >> k;
	for(int i=0;i<k;i++){
		char x;
		int y;
		cin >> x >> y;
		istr.push_back(make_pair(x,y));
	}
	for(int i=0;i<n;i++)for(int j=1;j<m;j++)rig[i][j]=isola[i][j];
	for(int i=0;i<n;i++)for(int j=1;j<m;j++)col[i][j]=isola[i][j];
	for(int i=0;i<n;i++)for(int j=1;j<m;j++)rig[i][j]+=rig[i][j-1];
	for(int i=1;i<n;i++)for(int j=0;j<m;j++)col[i][j]+=col[i-1][j];
	
	//~ for(int i=0;i<n;i++){
		//~ for(int j=0;j<m;j++)cout << col[i][j];
		//~ cout << endl;
	//~ }
	//~ return 0;
	vector <char> res;
	for(int i=0;i<int(sight.size());i++){
		if(prova(sight[i].first,sight[i].second)){
			res.push_back(nome[i]);
		}
	}
	if(res.empty())cout << "no solution";
	else{
		sort(res.begin(),res.end());
		for(int i=0;i<int(res.size());i++)cout << res[i];
	}
}