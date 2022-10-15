#include <bits/stdc++.h>
using namespace std;int main(){long long t,i;cin>>t;t+=2000;cout<<"2000\n-1 ";for(i=1;i<2000;i++){cout<<min((long long)1e6,t)<<" ";t-=min((long long)1e6,t);}}