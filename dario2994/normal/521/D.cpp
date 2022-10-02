#include <iostream>
#include <algorithm>
#include <vector>
#define MAXK 110000
#define MAXN 110000
using namespace std;

int k,n,m;
int a[MAXK];
int tipo[MAXN];
pair <int,int> ass[MAXK];
vector < pair<int,int> > sum[MAXK];
vector <pair <double,int> > all;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> k >> n >> m;
	for(int i=1;i<=k;i++) cin >> a[i];
	for(int j=1;j<=n;j++) {
		int t,i,b;
		cin >> t >> i >> b;
		tipo[j]=t;
		if( t==1 ) {
			if( b>=ass[i].first ) ass[i]=make_pair(b,j);
		}
		else if( t==2 ) sum[i].push_back(make_pair(b,j));
		else if( t==3 ) all.push_back(make_pair(b,j));
	}
	for(int i=1;i<=k;i++) if( ass[i].first > a[i] ) sum[i].push_back(make_pair( ass[i].first-a[i],ass[i].second) );
	for(int i=1;i<=k;i++) {
		sort(sum[i].rbegin(), sum[i].rend());
		long long int s=a[i];
		for(int j=0;j<(int)sum[i].size();j++) {
			long long int x=sum[i][j].first;
			all.push_back( make_pair( (double)(s+x)/(double)s ,sum[i][j].second ));
			s+=x;
		}
	}
	sort(all.rbegin(), all.rend());
	
	m=min((int)all.size(), m);
	cout << m << "\n";
	
	for(int j=0;j<m;j++) if( tipo[all[j].second]==1 ) cout << all[j].second << " ";
	for(int j=0;j<m;j++) if( tipo[all[j].second]==2 ) cout << all[j].second << " ";
	for(int j=0;j<m;j++) if( tipo[all[j].second]==3 ) cout << all[j].second << " ";
}