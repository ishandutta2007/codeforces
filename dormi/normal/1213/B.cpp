#include <bits/stdc++.h>
using namespace std;
#define pb push_back;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
const int MAXN=(int)1e6+1;
int bit[MAXN];
void update(int loc, int am){
	for(;loc<=(int)1e6;loc+=loc&-loc){
		bit[loc]+=am;
	}
}
int query(int loc){
	int sum=0;
	for(;loc>0;loc-=loc&-loc){
		sum+=bit[loc];
	}
	return sum;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
    	int n;
    	cin>>n;
    	int in;
    	vector<int> used;
    	int cnt=0;
    	for(int i=0;i<n;i++){
			cin>>in;
			used.push_back(in);
    	}
    	for(int i=n-1;i>=0;i--){
		    if(query(used[i]-1))cnt+=1;
		    update(used[i],1);
    	}
    	for(int x:used)update(x,-1);
    	printf("%d\n",cnt);
    }
    return 0;
}