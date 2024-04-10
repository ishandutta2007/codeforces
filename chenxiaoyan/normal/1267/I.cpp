#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100;
int n;
int rel[2*N+1][2*N+1];
void ask(int x,int y){
	if(rel[x][y])return;
	printf("? %d %d\n",x,y);
	char c;
	cin>>c;
	if(c=='>')swap(x,y);
	rel[x][y]=1;rel[y][x]=2;
}
int weaker[2*N+1];
int weakest(vector<int> v){
	memset(weaker,0,sizeof(weaker));
	for(int i=0;i<v.size();i++)for(int j=0;j<v.size();j++)
		if(i!=j){
			ask(v[i],v[j]);
			weaker[rel[v[i]][v[j]]==1?j:i]++;
		}
	for(int i=0;i<v.size();i++)if(weaker[i]==0)return v[i];
}
void mian(){
	cin>>n;
	memset(rel,0,sizeof(rel));
	vector<int> v1,v2;
	v1.pb(1);v1.pb(2);
	for(int i=3;i<=n;i++)v2.pb(i);
	for(int i=n+1;i<=2*n;i++){
		if(v1.size()==1)v1.pb(i);
		else v2.pb(i);
		int w1=weakest(v1),w2=weakest(v2);
		ask(w1,w2);
		if(rel[w1][w2]==1)v1.erase(find(v1.begin(),v1.end(),w1));
		else v2.erase(find(v2.begin(),v2.end(),w2));
	}
	puts("!");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}