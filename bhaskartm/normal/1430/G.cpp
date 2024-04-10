#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int

#define pb push_back
#define endl '\n'
#define T long double
#define EPS 1e-9

struct LPSolver{
	int m, n;
	vector<int>B, N;
	vector<vector<T> >D;
	LPSolver(const vector<vector<T> > &A, const vector<T> &b, const vector<T> &c)
		:
		m(b.size()), n(c.size()), N(n+1), B(m), D(m+2, vector<T>(n+2)){
			for(int i=0; i<m; i++){
				for(int j=0; j<n; j++){
					D[i][j]=A[i][j];
				}
			}
			for(int i=0; i<m; i++){
				B[i]=n+i;
				D[i][n]=-1;
				D[i][n+1]=b[i];
			}
			for(int j=0; j<n; j++){
				N[j]=j;
				D[m][j]=-c[j];
			}
			N[n]=-1;
			D[m+1][n]=1;
		}
	void Pivot(int r, int s){
		for(int i=0; i<m+2; i++){
			if(i!=r){
				for(int j=0; j<n+2; j++){
					if(j!=s){
						D[i][j]-=D[r][j]*D[i][s]/D[r][s];
					}
				}
			}
		}
		for(int j=0; j<n+2; j++){
			if(j!=s){
				D[r][j]/=D[r][s];
			}
		}
		for(int i=0; i<m+2; i++){
			if(i!=r){
				D[i][s]/=-D[r][s];
			}
		}
		D[r][s]=1.0/D[r][s];
		swap(B[r], N[s]);
	}
	bool Simplex(int phase){
		int x=phase==1 ? m+1 : m;
		while(true){
			int s=-1;
			for(int j=0; j<=n; j++){
				if(phase==2 && N[j]==-1){
					continue;
				}
				if(s==-1 || D[x][j]<D[x][s] || D[x][j]==D[x][s] && N[j]<N[s]){
					s=j;
				}
			}
			if(D[x][s]>-EPS){
				return true;
			}
			int r=-1;
			for(int i=0; i<m; i++){
				if(D[i][s]<EPS){
					continue;
				}
				if(r==-1 || D[i][n+1]/D[i][s]<D[r][n+1]/D[r][s] || (D[i][n+1]/D[i][s])==(D[r][n+1]/D[r][s]) && B[i]<B[r]){
					r=i;
				}
			}
			if(r==-1){
				return false;
			}
			Pivot(r, s);
		}
	}
	T Solve(vector<T> &x){
		int r=0;
		for(int i=1; i<m; i++){
			if(D[i][n+1]<D[r][n+1]){
				r=i;
			}
		}
		if(D[r][n+1]<-EPS){
			Pivot(r, n);
			if(!Simplex(1) || D[m+1][n+1]<-EPS){
				return -numeric_limits<T>::infinity();
			}
			for(int i=0; i<m; i++){
				if(B[i]==-1){
					int s=-1;
					for(int j=0; j<=n; j++){
						if(s==-1 || D[i][j]<D[i][s] || D[i][j]==D[i][s] && N[j]<N[s]){
							s=j;
						}
					}
					Pivot(i, s);
				}
			}
		}
		if(!Simplex(2)){
			return numeric_limits<T>::infinity();
		}
		x=vector<T>(n);
		for(int i=0; i<m; i++){
			if(B[i]<n){
				x[B[i]]=D[i][n+1];
			}
		}
		return D[m][n+1];
	}
};
 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int m;
	cin>>n>>m;
	vector<vector<T>>A;
	vector<T>c;
	A.resize(m);
	vector<T>b;
	c.resize(n);
	for(int i=0; i<n; i++){
		c[i]=0;
	}
	
	for(int i=0; i<m; i++){
		int u, v, w;
		cin>>u>>v>>w;
		u--;
		v--;
		for(int j=0; j<n; j++){
			if(j==v){
				A[i].pb(1);
			}
			else if(j==u){
				A[i].pb(-1);
			}
			else{
				A[i].pb(0);
			}
		}
		b.pb(-1);
		c[v]+=w;
		c[u]-=w;
	}
	
	LPSolver solver(A, b, c);
	vector<T>xx;
	
	T ans=solver.Solve(xx);
	for(size_t i=0; i<xx.size(); i++){
		cout<<round(xx[i])<<" ";
	}
	
	
	
	
/*	while(1){
		int n;
		cin>>n;
		if(n==0){
			return 0;
		}
		int m=(n*(n-1))/2;
		int x[n];
		int y[n];
		for(int i=0; i<n; i++){
			cin>>x[i]>>y[i];
		}
		vector<T>c;
		for(int i=0; i<n; i++){
			c.pb(1);
		}
		vector<vector<T> >A;
		vector<T>b;
		A.resize(m);
		int pt=0;
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				for(int k=0; k<n; k++){
					if(k==i || k==j){
						A[pt].pb(1);
					}
					else{
						A[pt].pb(0);
					}
				}
				T val=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
				b.pb(val);
				pt++;
			}
		}
		LPSolver solver(A, b, c);
		vector<T>xx;
		T ans=solver.Solve(xx);
		cout<<ans<<endl;
	}*/
	
	return 0;
}