#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
int main(){
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n,t,k;
	cin>>n>>k;
	pair<int,int> a[n];
	for(int i=0;i<n;i++){
        cin>>t;
        a[i]={t,i+1};
	}
	sort(a,a+n);
	cout<<a[n-k].fr<<"\n";
	for(int i=n-k;i<n;i++){
        cout<<a[i].sc<<" ";
	}
}