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
 
int p[1000005],n;
int dis[110][110];
string s[110];
 
void caldis(int z){
	deque<pii> q;
	q.pb({z,0});
	while(!q.empty()){
		int a=q.front().fr,b=q.front().sc;
		q.pop_front();
		if(dis[z][a])continue;
		dis[z][a]=b;
		for(int i=0;i<n;i++){
			if(dis[z][i]||s[a][i]=='0'||i==z)continue;
			q.pb({i,b+1});
		}
	}
}
vector<int> ans;
void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>s[i];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
    	cin>>p[i];
    }
    for(int i=0;i<n;i++){
    	caldis(i);
    }
    int h=0,f=m-1;
    while(h<f){//cout<<p[h]<<"-"<<h<<"\n";
    	ans.pb(p[h]);
    	int i=1312425;
    	for(i=h+1;i<=f;i++){
    		//cout<<p[h]<<" "<<p[i]<<" "<<dis[p[h]-1][p[i]-1]<<"\n";
    		if(dis[p[h]-1][p[i]-1]<i-h||p[h]==p[i]){
    			h=i-1;
    			break;
    		}
    	}
    	if(i>f)break;
    }
    cout<<ans.size()+1<<"\n";
    for(int x:ans){
    	cout<<x<<" ";
    }
    cout<<p[f];
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