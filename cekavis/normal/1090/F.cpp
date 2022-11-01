#include<bits/stdc++.h>

using namespace std;

// const int Ans[]={0, 1, 0, 2, 1, 3};
int n, q[6], d[6], f[6][6][6], ans[1005];
vector<int> e[6];
int ask(int x, int y, int z){
	// return min(min(Ans[x], Ans[y]), Ans[z])+max(max(Ans[x], Ans[y]), Ans[z]);
	cout<<"? "<<x<<' '<<y<<' '<<z<<endl;
	cin>>x;
	return x;
}
void solve(int x){
	memset(d, 0, sizeof d);
	for(int i=1; i<=5; ++i) e[i].clear();
	for(int i=1; i<4; ++i) for(int j=i+1; j<5; ++j) for(int k=j+1; k<=5; ++k)
		f[j][i][k]=f[j][k][i]=f[k][i][j]=f[k][j][i]=f[i][k][j]=f[i][j][k]=ask(x+i-1, x+j-1, x+k-1);
	for(int i=1; i<5; ++i) for(int j=i+1; j<=5; ++j)
		for(int k=1; k<=5; ++k) if(k!=i && k!=j) for(int t=1; t<=5; ++t) if(k!=i && t!=j)
			if(f[i][j][k]<f[i][j][t]) e[t].push_back(k), ++d[k];
	int r=0;
	for(int i=1; i<=5; ++i) if(!d[i]) q[++r]=i;
	for(int l=1; l<=r; ++l){
		int x=q[l];
		for(int i:e[x]) if(!--d[i]) q[++r]=i;
	}
	int a=f[q[1]][q[3]][q[5]], b=f[q[1]][q[2]][q[3]], c=f[q[3]][q[4]][q[5]];
	ans[x+q[1]-1]=(a+b-c)/2, ans[x+q[3]-1]=(b+c-a)/2, ans[x+q[5]-1]=(a+c-b)/2;
	ans[x+q[2]-1]=f[q[2]][q[3]][q[5]]-ans[x+q[5]-1];
	ans[x+q[4]-1]=f[q[1]][q[3]][q[4]]-ans[x+q[1]-1];
}
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; i+=5) solve(min(i, n-4));
	cout<<"!";
	for(int i=1; i<=n; ++i) cout<<' '<<ans[i];
	return cout<<endl, 0;
}