#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=80;
ll a[N][N],mn[N][N],mx[N][N],fib[N],K;
int n,x,y,Q;

void init(){
	fib[0]=fib[1]=1;
	rep(i,2,78){
		fib[i]=fib[i-1]+fib[i-2];
//		printf("# %d %lld\n",i,fib[i]);
	}
}

int main(){
	init();
	cin>>n;
	rep(i,1,n){
		rep(j,1,n){
			if(i>=2||j>=2) a[i][j]=fib[78-i-2*j];
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	mn[n][n]=mx[n][n]=a[n][n];
	per(i,n,1){
		per(j,n-(i==n),1){
			mn[i][j]=1e18;
			if(i<n){
				mn[i][j]=min(mn[i][j],mn[i+1][j]+a[i][j]);
				mx[i][j]=max(mx[i][j],mx[i+1][j]+a[i][j]);
			}
			if(j<n){
				mn[i][j]=min(mn[i][j],mn[i][j+1]+a[i][j]);
				mx[i][j]=max(mx[i][j],mx[i][j+1]+a[i][j]);
			}
		}
	}
	cin>>Q;
	for(;Q;Q--){
		cin>>K;
		x=y=1;
		for(;x<n||y<n;){
			cout<<x<<" "<<y<<endl;
			K-=a[x][y];
			if(x<n&&(y==n||K>=mn[x+1][y])){
				x++;
			}
			else{
				y++;
			}
		}
		cout<<x<<" "<<y<<endl;
	}

	return 0;
}