#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,m,I[100004],p[100004];
vector<int>g[100004];
priority_queue<int>pq;
int main(){
	read(n),read(m);
	while (m--){
		int x,y;read(x),read(y),g[y].push_back(x); 
		I[x]++;
	}
	for (int i=1;i<=n;i++) if (I[i]==0) pq.push(i); 
	for (int i=n;i>=1;i--){
		int v=pq.top();pq.pop();
		p[v]=i;
		for (int i=0;i<g[v].size();i++){
			I[g[v][i]]--;
			if (I[g[v][i]]==0) pq.push(g[v][i]); 
		}
	}
	for (int i=1;i<=n;i++) write(p[i]),putchar(' ');
}