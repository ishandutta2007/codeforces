#include <bits/stdc++.h>

using namespace std;

struct rect{ int x1, y1, x2, y2; };

rect P[101010];

struct cmp1{ bool operator() (int &ca, int &cb) { return P[ca].x1 > P[cb].x1; } };
struct cmp2{ bool operator() (int &ca, int &cb) { return P[ca].x2 < P[cb].x2; } };
struct cmp3{ bool operator() (int &ca, int &cb) { return P[ca].y1 > P[cb].y1; } };
struct cmp4{ bool operator() (int &ca, int &cb) { return P[ca].y2 < P[cb].y2; } };

int chk[101010];
int n, cnt;

bool f(vector <int> &V)
{
	int x = ++cnt;
	
	for(int &t: V){
		chk[t] = x;
	}
	
	if(V.size() == 1) return 1;
	
	vector <int> X1, X2, X3, X4;
	priority_queue <int, vector <int>, cmp1> Q1;
	priority_queue <int, vector <int>, cmp2> Q2;
	priority_queue <int, vector <int>, cmp3> Q3;
	priority_queue <int, vector <int>, cmp4> Q4;
	int lx, rx, ly, ry, k, b;
	
	for(int &t: V){
		Q1.push(t); Q2.push(t);
		Q3.push(t); Q4.push(t);
	}
	
	for(; ; ){
		if(Q1.empty() || Q2.empty() || Q3.empty() || Q4.empty()) return 1;
		
		X1.clear(); X2.clear(); X3.clear(); X4.clear();
		lx = ly = 1e9; rx = ry = 0;
		
		for(; ; ){
			for(; !Q1.empty() && chk[Q1.top()] > x; Q1.pop());
			for(; !Q2.empty() && chk[Q2.top()] > x; Q2.pop());
			for(; !Q3.empty() && chk[Q3.top()] > x; Q3.pop());
			for(; !Q4.empty() && chk[Q4.top()] > x; Q4.pop());
			
			if(Q1.empty()){ b = 1; break; }
			k = Q1.top(); if(P[k].x1 >= rx && !X1.empty()) { b = 1; break; }
			X1.push_back(k); rx = max(rx, P[k].x2); Q1.pop();
			
			if(Q2.empty()){ b = 2; break; }
			k = Q2.top(); if(P[k].x2 <= lx && !X2.empty()) { b = 2; break; }
			X2.push_back(k); lx = min(lx, P[k].x1); Q2.pop();
			
			if(Q3.empty()){ b = 3; break; }
			k = Q3.top(); if(P[k].y1 >= ry && !X3.empty()) { b = 3; break; }
			X3.push_back(k); ry = max(ry, P[k].y2); Q3.pop();
			
			if(Q4.empty()){ b = 4; break; }
			k = Q4.top(); if(P[k].y2 <= ly && !X4.empty()) { b = 4; break; }
			X4.push_back(k); ly = min(ly, P[k].y1); Q4.pop();
			
			if(X1.size() * 2 > V.size()) return 0;
		}
		
		if(b == 1 && !f(X1)) return 0;
		if(b == 2 && !f(X2)) return 0;
		if(b == 3 && !f(X3)) return 0;
		if(b == 4 && !f(X4)) return 0;
		
		if(b != 1) for(int &t: X1) if(chk[t] <= x) Q1.push(t);
		if(b != 2) for(int &t: X2) if(chk[t] <= x) Q2.push(t);
		if(b != 3) for(int &t: X3) if(chk[t] <= x) Q3.push(t);
		if(b != 4) for(int &t: X4) if(chk[t] <= x) Q4.push(t);
	}
	
	return 1;
}

int main()
{
	vector <int> V;
	int i;
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%d%d%d%d", &P[i].x1, &P[i].y1, &P[i].x2, &P[i].y2);
		V.push_back(i);
	}
	
	printf("%s\n", f(V)? "YES" : "NO");
	
	return 0;
}