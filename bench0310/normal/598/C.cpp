#include <bits/stdc++.h>

using namespace std;

const long double pi=3.141592653589793238462643383279502884;

long double angle(long double a,long double b)
{
    if(a<0) a+=2*pi;
    if(b<0) b+=2*pi;
    return min(max(a-b,b-a),2*pi-max(a-b,b-a));
}

int main()
{
    int n;
    cin >> n;
    vector<pair<long double,int>> v(n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        v[i]=make_pair(atan2l(y,x),i+1);
    }
    sort(v.begin(),v.end());
    pair<int,int> res={0,n-1};
    for(int i=0;i<n-1;i++)
    {
        if(angle(v[i].first,v[i+1].first)<angle(v[res.first].first,v[res.second].first)) res={i,i+1};
    }
    cout << v[res.first].second << " " << v[res.second].second << endl;
    return 0;
}