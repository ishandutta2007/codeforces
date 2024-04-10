#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    cin >> n >> m;
    bool a[n];
    fill(a,a+n,true);
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        a[x-1]=false;
        a[y-1]=false;
    }
    vector<pair<int,int> > v;
    for(int i=0; i<n; i++){
        if(a[i]){
            for(int j=0; j<n; j++){
                if(i!=j) v.push_back(make_pair(i+1,j+1));
            }
            break;
        }
    }
    cout << v.size() << '\n';
    for(int i=0; i<v.size(); i++) cout << v[i].first << ' ' << v[i].second << '\n';
	return 0;
}