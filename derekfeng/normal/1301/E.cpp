#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
inline int nxt(){
	int x;
	cin>>x;
	return x;
}
void remin(int& x,int y){
	x=min(x,y);
}
const int L=9;
const int N=1<<L; 
struct Sparse{
	array<array<int,N>,L>a;
	Sparse(){}
	Sparse(const vector<int>& ar) {
		int n = ar.size();
		for (int i = 0; i < N; ++i) {
			a[0][i] = (i < n) ? ar[i] : 0;
		}
		for (int j = 1; j < L; ++j) {
			for (int i = 0; i + (1 << j) <= N; ++i) {
				a[j][i] = max(a[j - 1][i], a[j - 1][i + (1 << (j - 1))]);
			}
		}
	}
	int get(int l, int r){
		const int b=31-__builtin_clz(r-l);
		return max(a[b][l],a[b][r-(1<<b)]);
	}
};
const string colors="RGYB";
int a[N][N];
enum Dir : int{
	North=0,
	West=1,
	South=2,
	East=3
};
int max_len[N][N][4];
int max_sq[N][N];
int value[N][N];
Sparse hor[N],ver[N];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n=nxt(),m=nxt(),q=nxt();
	for (int i=0;i<n;++i){
		string s;
		cin>>s;
		for (int j=0;j<m;++j){
			a[i][j]=colors.find(s[j]);
		}
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			max_len[i][j][North]=max_len[i][j][West]=1;
			if (i>0 && a[i][j]==a[i-1][j]){
				max_len[i][j][North]+=max_len[i-1][j][North];
			}
			if (j>0 && a[i][j]==a[i][j-1]){
				max_len[i][j][West]+=max_len[i][j-1][West];
			}
		}
	}
	for (int i=n-1;i>=0;--i){
		for (int j=m-1;j>=0;--j){
			max_len[i][j][South]=max_len[i][j][East]=1;
			if (i<n-1 && a[i][j]==a[i + 1][j]){
				max_len[i][j][South]+=max_len[i+1][j][South];
			}
			if (j<m-1 && a[i][j]==a[i][j+1]){
				max_len[i][j][East]+=max_len[i][j+1][East];
			}
		}
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			max_sq[i][j]=1e9;
		}
	}
	for (int i=0;i<n;++i){
		for (int j=0;j<m;++j){
			if (a[i][j]==0 || a[i][j]==1){
				remin(max_sq[i][j],max_len[i][j][North]);
			}
			if (a[i][j]==0 || a[i][j]==2){
				remin(max_sq[i][j],max_len[i][j][West]);
			}
			if (a[i][j]==0){
				remin(max_sq[i][j],1+(i>0 && j>0 && a[i][j]==a[i-1][j-1]?max_sq[i-1][j-1]:0));
			}
			if (a[i][j]==1){
				remin(max_sq[i][j],1+(i>0 && j<m-1 && a[i][j]==a[i-1][j+1]?max_sq[i-1][j+1]:0));
			}
		}
	}
	for (int i=n-1;i>=0;--i){
		for (int j=m-1;j>=0;--j){
			if (a[i][j]==3 || a[i][j]==2){
				remin(max_sq[i][j],max_len[i][j][South]);
			}
			if (a[i][j]==3 || a[i][j]==1){
				remin(max_sq[i][j],max_len[i][j][East]);
			}
			if (a[i][j] == 2){
				remin(max_sq[i][j],1+(i<n-1 && j>0 && a[i][j]==a[i+1][j-1]?max_sq[i+1][j-1]:0));
			}
			if (a[i][j]==3){
				remin(max_sq[i][j],1+(i<n-1 && j<m-1 && a[i][j]==a[i+1][j+1]?max_sq[i+1][j+1]:0));
			}
		}
	}
	for (int i=1;i<n;++i){
		for (int j=1;j<m;++j){
			if (a[i-1][j-1]!=0 || a[i-1][j]!=1 || a[i][j-1]!= 2 || a[i][j]!=3){
				continue;
			}
			value[i-1][j-1]=min({max_sq[i-1][j-1], max_sq[i-1][j],max_sq[i][j-1],max_sq[i][j]});
		}
	}
	for (int i=0;i<n-1;++i){
		hor[i]=Sparse(vector<int>{value[i],value[i]+m-1});
	}
	for (int j=0;j<m-1;++j){
		vector<int>v;
		for (int i=0;i<n-1;++i){
			v.push_back(value[i][j]);
		}
		ver[j]=Sparse(v);
	}
	while (q--){
		int lx=nxt()-1,ly=nxt()-1,rx=nxt()-1,ry=nxt()-1;
		int ans=0;
		for (int i=1;lx<rx && ly<ry;++i){
			ans=max(ans,min(i,hor[lx].get(ly,ry)));
			ans=max(ans,min(i,hor[rx-1].get(ly,ry)));
			ans=max(ans,min(i,ver[ly].get(lx,rx)));
			ans=max(ans,min(i,ver[ry-1].get(lx,rx)));
			++lx;
			++ly;
			--rx;
			--ry;
		}
		cout<<4*ans*ans<<"\n";
	}
	return 0;
}