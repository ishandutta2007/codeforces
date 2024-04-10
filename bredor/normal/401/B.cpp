#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define pb push_back

int main(){

    int x, k;
    cin>>x>>k;
    vector<pair<int, int> >V;

    V.pb(make_pair(x, x + 1));
    V.pb(make_pair(0,0));

    for(int i = 0; i<k; ++i){
        int t;
        cin>>t;
        if (t == 1){int a, b; cin>>a>>b;V.pb(make_pair(a, b));}
        else
        {int a; cin>>a; V.pb(make_pair(a, a));}
    }

    sort(V.begin(), V.end());

    int minn = 0;
    int maxx = 0;

    for(int i = 1; i < V.size(); ++i){

        int a = V[i].first - V[i - 1].second - 1;
        minn+=(a + 1)/2;
        maxx += a;

    }

    cout<<minn<<" "<<maxx<<"\n";


}