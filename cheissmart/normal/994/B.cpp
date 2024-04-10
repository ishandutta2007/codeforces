#include<bits/stdc++.h>
#define ll long long
#define N 100005

using namespace std;

ll p[N], c[N], b[N], a[N];

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);

    ll n, k, x, i, j, sum = 0;
    cin >> n >> k;
    vector<pair<ll,ll> > v;
    multiset<ll> s;
    for(i = 0;i < n;i++) {
		cin >> p[i]; 
		b[i] = p[i];
	}
    for(i = 0;i < n;i++) 
		cin >> c[i];
    for(i = 0;i < n;i++) 
		v.push_back(make_pair(p[i],c[i]));
		
    sort(v.begin(),v.end());
    sort(b,b + n);
    if(k == 0){
        for(i=0;i < n;i++) cout << c[i] << " ";
        return 0;
    }
    for(i=0;i < n;i++){
        a[i] = v[i].second+sum;
        if(s.size() < k){
            s.insert(v[i].second);
            sum += v[i].second;
        }
        else if(s.size() == k){
            if(v[i].second > *(s.begin())){
                sum=sum-*(s.begin()) + v[i].second;
                s.erase(s.begin());
                s.insert(v[i].second);
            }
        }
    }
    for(i=0;i<n;i++)
        cout << a[lower_bound(b,b+n,p[i])-b] << " ";
}