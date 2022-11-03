#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> lll;
typedef pair<ll,int> lli;
typedef pair<int,int> ii;

#define EL printf("\n")
#define OK printf("OK")
#define pb push_back
#define mp make_pair
#define ep emplace_back
#define X  first
#define Y  second
#define fillchar(a,x) memset(a, x, sizeof(a))
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)


struct Edge{int to; int w; int index;};

vector<vector<Edge> > data;
vector<vector<int> > cycles;
vector<bool> used;
vector<bool> in_cycle;
vector<int> weights;
void dfs(int vertex, int last, int ledge, vector<pair<int, int> > &path){
	used[vertex] = true;
	path.push_back({vertex, ledge});
	for (int i=0; i < data[vertex].size(); ++i){
		int to = data[vertex][i].to;
		if (to==last) continue;
		if (used[to]){
			int E = data[vertex][i].index;
			if (in_cycle[E]) continue;
			in_cycle[E] = true;
			cycles.push_back({weights[E]});
			int index = path.size() - 1;
			while (path[index].first != to){
				in_cycle[path[index--].second] = true;
				cycles.back().push_back({weights[path[index+1].second]});
			}
			continue;
		}
		dfs(to, vertex, data[vertex][i].index, path);
	}
	path.pop_back();
}



const int K = 1<<17;
const int mod1 = 1000000007;
const int mod2 = 998244353;

int sum(int x, int y){
	if (x + y < 0) return x+y+mod1;
	if (x+y >= mod1) return x+y-mod1;
	return x+y;
}

int mult(int x, int y){
	return ((ll) x * (ll) y) % (ll) mod1;
}

vector<int> hadamard(vector<int> v){
    for (int step=K; step > 1; step /= 2){
        for (int start=0; start < K; start += step){
            for (int w=0; w < step/2; w++){
                int F = sum(v[start+w], v[start+step/2+w]);
                int S = sum(v[start+w], -v[start+step/2+w]);
             	//cout << v[start+w] << " " << v[start+step/2+w] << " " << F << endl; 
                v[start + w] = F;
                v[start+step/2+w] = S;
            }
        }
    }
    return v;
}

int pw(int a, int b){
	if (b==0) return 1;
	if (b==1) return a%mod1;
	if (b%2) return mult(a, pw(a, b-1));
	int R = pw(a, b/2);
	return mult(R, R);
}

int rev1 = pw(K, mod1-2);

vector<int> mult(vector<int> v, vector<int> u){
	v = hadamard(v), u = hadamard(u);
    for (int i=0; i < K; i++) v[i] = mult(v[i], u[i]);
    v = hadamard(v);
    for (int i=0; i < K; i++){
    	v[i] = mult(v[i], rev1);
    }
    //cout << v[0] << endl;
    return v;
}




int sum2(int x, int y){
	if (x + y < 0) return x+y+mod2;
	if (x+y >= mod2) return x+y-mod2;
	return x+y;
}

int mult2(int x, int y){
	return ((ll) x * (ll) y) % (ll) mod2;
}

vector<int> hadamard2(vector<int> v){
    for (int step=K; step > 1; step /= 2){
        for (int start=0; start < K; start += step){
            for (int w=0; w < step/2; w++){
                int F = sum2(v[start+w], v[start+step/2+w]);
                int S = sum2(v[start+w], -v[start+step/2+w]);
             	//cout << v[start+w] << " " << v[start+step/2+w] << " " << F << endl; 
                v[start + w] = F;
                v[start+step/2+w] = S;
            }
        }
    }
    return v;
}

int pw2(int a, int b){
	if (b==0) return 1;
	if (b==1) return a%mod2;
	if (b%2) return mult2(a, pw2(a, b-1));
	int R = pw2(a, b/2);
	return mult2(R, R);
}

int rev2 = pw2(K, mod2-2);

vector<int> mult2(vector<int> v, vector<int> u){
	v = hadamard2(v), u = hadamard2(u);
    for (int i=0; i < K; i++) v[i] = mult2(v[i], u[i]);
    v = hadamard2(v);
    for (int i=0; i < K; i++){
    	v[i] = mult2(v[i], rev2);
    }
    //cout << v[0] << endl;
    return v;
}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	data.assign(n, {});
	for (int i=0;i<m;++i){
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		data[u].push_back({v, w, i}), data[v].push_back({u, w, i});
		weights.push_back(w);
	}
	if (m==n-1){
		int X = 0;
		for (int i=0;i<m;++i) X ^= weights[i];
		cout << X << " " << 1 << endl;
	return 0;
	}
	in_cycle.assign(m, false);
	used.assign(n, false);
	vector<pair<int, int> > p;
	dfs(0, -1, -1, p);

	vector<int> start(K, 0), start2(K, 0);
	int st = 0;
	for (int i=0; i < cycles[0].size(); ++i) st ^= cycles[0][i];
	for (int i=0; i < cycles[0].size(); ++i){
		start[st^cycles[0][i]]+=1;
		start2[st^cycles[0][i]]+=1;
		//cout << (st^cycles[0][i]) << " ";
	}
	//cout << endl;
	for (int i=1; i < cycles.size(); ++i){
		vector<int> tut(K, 0);
		vector<int> tut2(K, 0);
		int R = 0;
		for (int j=0; j < cycles[i].size(); ++j) R ^= cycles[i][j];
		for (int j=0; j < cycles[i].size(); ++j){
			tut[R^cycles[i][j]]+=1;
			tut2[R^cycles[i][j]]+=1;
			//cout << (R^cycles[i][j]) << " ";
		}
		//cout << 
		start = mult(start, tut);
		start2 = mult2(start2, tut2);
		//cout << start[0] << endl;
	}
	int mn = 1e9;
	int cnt = -1;
	int X = 0;
	for (int i=0; i < m; ++i) if (!in_cycle[i]){
		X ^= weights[i];
	}
	for (int i=0;i<K;++i){
		//cout << start[i] << " ";
		int T = X^i;
		if ((start[i] > 0 || start2[i] > 0) && T < mn){
			mn = T;
			cnt = start[i];
		}
	}
	cout << mn << " " << cnt;

}