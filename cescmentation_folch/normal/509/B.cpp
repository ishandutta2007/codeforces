#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<math.h>
#include<set>
#include<algorithm>
#include<string>
#include<stack>
#include<iomanip>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define forl(i,a,f) for(int i = (int)a;i <= (int)f;++i)
#define rofl(i,a,f) for(int i = (int)a;i >= (int)f;--i)
#define pb push_back
#define pi 3.14159265
#define inf 2e9
#define INF 9e18
#define minll(a,b) ((long long)a < (long long)b)? a : b
#define maxll(a,b) ((long long)a > (long long)b)? a : b

typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> Vll;
typedef vector<Vll> VVll;
typedef pair<ll ,ll> Pll;
typedef vector<Pll> VPll;
typedef vector<VPll> VVPll;
typedef pair<int, int> PI;
typedef pair<bool , int> PBI;
typedef pair<PI,PBI> PIB;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef queue<int> QI;
typedef priority_queue<PI> PQPI;
typedef queue<PI> QPI;
typedef queue<PIB> QPIB;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef stack<int> SI;

int main(){
	int n,k;
	cin>>n>>k;
	int b[n];
	int max,min;
	cin>>b[0];
	min = b[0];
	max = b[0];
	forl(i,1,n-1){
		cin>>b[i];
		if(b[i] > max) max = b[i];
		if(b[i] < min) min = b[i];
	} 
	if(min+k < max) cout<<"NO"<<endl;
	else{
		cout<<"YES"<<endl;
		bool x;
		forl(i,0,n-1){
			x = false;
			forl(j,1,k){
				forl(w,1,b[i]/k){
					if(x) cout<<" ";
					else x = true;
					cout<<j;
				}
				if(b[i]%k >= j){
					if(x) cout<<" ";
					else x = true;
					cout<<j;
				}
			}
			cout<<endl;
		}
	}
}