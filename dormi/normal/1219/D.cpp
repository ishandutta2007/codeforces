#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    lli k;
    sc(n,k);
    lli arr[n];
    for(int i=0;i<n;i++){
    	sc(arr[i]);
    }
    lli a;
    sc(a);
    lli cost=0;
    lli in;
    priority_queue<lli,vector<lli>,greater<lli>> q;
    for(int i=0;i<n;i++){
    	sc(in);
    	q.push(in);
    	while(q.size()&&k<arr[i]){
    		cost+=q.top();
    		q.pop();
    		k+=a;
    	}
    	if(k<arr[i]){
    		pr("-1\n");
    		return 0;
    	}
    }
    pr(cost);
    return 0;
}