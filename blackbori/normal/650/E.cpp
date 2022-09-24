#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

int P[505050], S[505050];
vector <pii> X, Y, Z;
set <pii> L;
int n;

int find(int p) { for(; p!=P[p]; p=P[p]); return p; }

void group(int &a, int &b)
{
	if(S[a] > S[b]) swap(a, b);
	P[a] = b; S[b] += S[a];
}

void rollback(pii &p) { S[p.second] -= S[p.first]; P[p.first] = p.first; }

void dnc(int s, int e, vector <pii> &V)
{
	if(s == e){
		Z.push_back(V[0]);
		return;
	}
	
	int i, k1, k2, k3, a, b;
	int mid = s + e >> 1;
	vector <pii> V1, V2, K;
	
	k1 = k2 = k3 = 0;
	
	for(i=mid+1; i<=e; i++){
		a = find(X[i].first); b = find(X[i].second);
		group(a, b);
		
		k1 ++;
		K.push_back(pii(a, b));
	}
	
	for(pii &t: V){
		a = find(t.first); b = find(t.second);
		if(a != b){
			V1.push_back(t);
			group(a, b);
			
			k2 ++;
			K.push_back(pii(a, b));
		}
		else V2.push_back(t);
	}
	
	for(; k2--; K.pop_back()) rollback(K.back());
	
	dnc(s, mid, V1);
	
	for(; k1--; K.pop_back()) rollback(K.back());
	
	for(pii &t: V1){
		a = find(t.first); b = find(t.second);
		group(a, b);
		
		k3 ++;
		K.push_back(pii(a, b));
	}
	
	dnc(mid + 1, e, V2);
	
	for(; k3--; K.pop_back()) rollback(K.back());
}

int main()
{
	int i, a, b;
	
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		P[i] = i; S[i] = 1;
	}
	
	for(i=1; i<n; i++){
		scanf("%d%d", &a, &b);
		if(a > b) swap(a, b);
		L.insert(pii(a, b));
	}
	
	for(i=1; i<n; i++){
		scanf("%d%d", &a, &b);
		if(a > b) swap(a, b);
		auto it = L.find(pii(a, b));
		if(it == L.end()){
			Y.push_back(pii(a, b));
		}
		else{
			L.erase(it);
			a = find(a); b = find(b);
			group(a, b);
		}
	}
	
	if(Y.size() == 0){
		printf("0\n");
		return 0;
	}
	
	for(auto &it: L){
		X.push_back(it);
	}
	
	dnc(0, X.size() - 1, Y);
	
	printf("%d\n", (int)X.size());
	
	for(i=0; i<X.size(); i++){
		printf("%d %d %d %d\n", X[i].first, X[i].second, Z[i].first, Z[i].second);
	}
	
	return 0;
}