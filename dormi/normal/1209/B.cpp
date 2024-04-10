#include<bits/stdc++.h>
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
    sc(n);
    string a;
    sc(a);
    pii arr[n];
    bool wh[n];
    for(int i=0;i<n;i++){
    	sc(arr[i].first,arr[i].second);
    	wh[i]=(a[i]=='1');
    }
    int ans=0;
    for(int i=0;i<=100000;i++){
    	int cnt=0;
    	for(int j=0;j<n;j++){
    		if(i>=arr[j].second&&(i-arr[j].second)%arr[j].first==0){
    			wh[j]=!wh[j];
    		}
    		if(wh[j])cnt+=1;
    	}
    	ans=max(ans,cnt);
    }
    pr(ans);
    return 0;
}