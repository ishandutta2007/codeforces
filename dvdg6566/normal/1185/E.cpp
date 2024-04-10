#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()

int N,R,C;
string S;
int grid[2010][2010];
int cnt[30],L;
pi st[30];
pi out1[30];
pi out2[30];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void run(){
	cin>>R>>C;
	memset(cnt,0,sizeof(cnt));
	L=0;
	for (int i=1;i<=R;++i){
		cin>>S;
		for (int j=1;j<=C;++j){
			if (S[j-1] == '.')grid[i][j] = 0;
			else {
				grid[i][j] = S[j-1] - 'a' + 1;
				++cnt[grid[i][j]];
				st[grid[i][j]] = mp(i,j);
				L = max(L,grid[i][j]);
			}
		}
	}
	// for (int i=1;i<=R;++i){
	// 	for (int j=1;j<=C;++j)cout<<grid[i][j]<<' ';
	// 		cout<<'\n';
	// }
	// for (int i=1;i<=L;++i)cout<<cnt[i]<<'\n';
	for (int col=1;col<=L;++col){
		int c = 1;
		out1[col] = out2[col] = st[col];
		for (int i=0;i<4;++i){
			int x = st[col].f;
			int y = st[col].s;
			while (x+dx[i] <= R && x+dx[i] > 0 && y+dy[i] <= C && y+dy[i] > 0){
				if (grid[x+dx[i]][y+dy[i]] < col)break;
				x += dx[i];
				y += dy[i];
				if (grid[x][y] == col){
					++c;
					if (i%2==0)out1[col]=mp(x,y);
					else out2[col]=mp(x,y);
				}
			}
			// cout<<"AT col "<<col<<' '<<i<<' '<<c<<'\n';

			if (i == 1 && c != 1 && c < cnt[col]){
				cout<<"NO\n";
				return;
			}
			if (i == 1 && c == cnt[col])break;
			if (i == 3 && c < cnt[col]){
				cout<<"NO\n";
				return;
			}
		}
	}

	cout<<"YES\n";
	cout<<L<<'\n';
	for (int i=1;i<=L;++i){
		if (cnt[i] == 0)cout<<st[L].f<<' '<<st[L].s<<' '<<st[L].f<<' '<<st[L].s<<'\n';
		else cout<<out1[i].f<<' '<<out1[i].s<<' '<<out2[i].f<<' '<<out2[i].s<<'\n';
	}
}
int main(){
	// freopen("in.txt","r",stdin);
	cin>>N;
	while(N--){
		run();
	}
}