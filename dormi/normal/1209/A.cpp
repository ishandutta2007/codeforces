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
bool done[101];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    sc(n);
    int arr[n];
    for(int i=0;i<n;i++)sc(arr[i]);
    sort(arr,arr+n);
    int cnt=0;
    for(int i=0;i<n;i++){
    	if(!done[arr[i]]){
    		cnt+=1;
    		for(int j=arr[i];j<=100;j+=arr[i]){
    			done[j]=true;
    		}
    	}
    }
    pr(cnt);
    return 0;
}