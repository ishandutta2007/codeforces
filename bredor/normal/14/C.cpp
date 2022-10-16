//  228

//Shinchan Loves Coding :))
#include<bits/stdc++.h>
#include<map>
#include<set>

using namespace std;

#define night_rider ios::sync_with_stdio(false);cin.tie(NULL);

#define double long double
#define int long long int
#define en "\n"
#define fi first
#define se second
#define PB push_back
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define rep(i,x,y) for(int i=x ; i<y ; i++)
#define erep(i,x,y) for(int i=x ; i<=y ; i++)
#define erepr(i,x,y) for(int i=x ; i>=y ; i--)
#define repr(i,x,y) for(int i=x ; i>y ; i--)
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> pii;

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

const int no=3e6+5,modulo=1e9+7,inf=1e18,N=3e3+1;
//int ar[no],br[no],cr[no];//,dr[no],er[no];//,mat[N][N];
//int used[no];
//int color[no];
//pii adj[no];
//vi adj[no];
//LOWER_BOUND(n) - FIRST ELEMENT GREATER THAN EQUAL TO n
//UPPER_BOUND(n) - FIRST ELEMENT GREATER THAN n

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

struct pt {
    int x,y;
};

void solve () {
    int n=0,m=0,a=0,b=0,c=0,d=0,z=0,w=0,k=0;
    map<pi,set<pi>> mapp;
    vector<pair<pt,pt>> v(4);
    a=inf;b=-inf;c=-inf;d=inf;
    rep(i,0,4) {
        cin>>v[i].fi.x>>v[i].fi.y>>v[i].se.x>>v[i].se.y;
        mapp[{v[i].fi.x,v[i].fi.y}].insert({v[i].se.x,v[i].se.y});
        mapp[{v[i].se.x,v[i].se.y}].insert({v[i].fi.x,v[i].fi.y});
        a=min(a,v[i].fi.x);c=max(c,v[i].fi.x);b=max(b,v[i].fi.y);d=min(d,v[i].fi.y);
        a=min(a,v[i].se.x);c=max(c,v[i].se.x);b=max(b,v[i].se.y);d=min(d,v[i].se.y);
    }
    if(mapp.size()==4) {
        if(mapp[{a,b}].size()!=2) cout<<"NO";
        else if(mapp[{a,d}].size()!=2) cout<<"NO";
        else if(mapp[{c,b}].size()!=2) cout<<"NO";
        else if(mapp[{c,d}].size()!=2) cout<<"NO";
        else {
            if(a==c || b==d) cout<<"NO";
            else cout<<"YES";
        }
    }
    else cout<<"NO";
}


inline void runn(){
	#ifndef ONLINE JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

signed main()
{
	night_rider
	//runn();
	int t=1;
	//cout<<fixed<<setprecision(15);
    //cin>>t;
	rep(i,1,t+1) {
        // cout << "Case #" << i << ": ";
        solve();
    }
}