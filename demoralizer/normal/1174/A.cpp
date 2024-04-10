#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
#define fbo               find_by_order
#define ook               order_of_key

template<typename T>
using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int a[100005];
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<2*n;i++){
    	cin>>a[i];
    }
    sort(a,a+2*n);
    int s1=0,s2=0;
    for(int i=0;i<n;i++){
    	s1+=a[i];
    	s2+=a[i+n];
    }
    if(s1==s2){
    	cout<<-1;
    }
    else{
    	for(int i=0;i<2*n;i++){
    		cout<<a[i]<<" ";
    	}
    }
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}