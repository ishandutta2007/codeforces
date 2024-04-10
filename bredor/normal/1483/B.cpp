// 228
#include <bits/stdc++.h>
using namespace std;int T,n,b,c;int main(){cin>>T;while(T--){cin>>n;vector<int>a(n),x(n),d(n,0),r;queue<int>q;for(int i=0;i<n;++i){cin>>a[i];q.push(i);x[i]=(i+1)%n;}while(!q.empty()){c=q.front(),b=x[c];q.pop();if(!d[c]&&__gcd(a[c],a[b])<2)r.push_back(b+1),q.push(c),d[b]=1,x[c]=x[b];}cout<<r.size()<<' ';for(int&e:r)cout<<e<<' ';cout<<'\n';}}