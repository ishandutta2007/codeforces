#include <bits/stdc++.h>
using namespace std;int main(){int a,b,c,d;cin>>a>>b>>c>>d;if (d<a) swap(a,d);if (d<b) swap(d,b);if (d<c) swap(d,c);cout<<d-a<<" "<<d-b<<" "<<d-c;}