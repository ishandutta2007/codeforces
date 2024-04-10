#include <bits/stdc++.h>
using namespace std;
main(){long long x1,y1,x2,y2,a,b,c,n,r=0;cin>>x1>>y1>>x2>>y2>>n;while(n--){cin>>a>>b>>c;if((a*x1+b*y1+c<0)!=(a*x2+b*y2+c<0))r++;}cout<<r<<endl;}