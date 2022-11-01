#include<bits/stdc++.h>
using namespace std;int64_t n,a,i,b;map<int,int64_t>m;main(){cin>>n;while(i++<n)cin>>b,m[b-i]+=b,a=max(a,m[b-i]);cout<<a;}